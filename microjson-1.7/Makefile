# Makefile for the microjson project

# The version for release is derived from the mostt recent stanza in the news file.
VERSION=$(shell sed -n <NEWS.adoc '/::/s/^\([0-9][^:]*\).*/\1/p' | head -1)

CFLAGS = -O

# Add DEBUG_ENABLE for the tracing code
CFLAGS += -DDEBUG_ENABLE -g
# Add TIME_ENABLE to support RFC3339 time literals
CFLAGS += -DTIME_ENABLE

all: mjson.o test_microjson example1 example2 example3 example4

mjson.o: mjson.c mjson.h

test_microjson: test_microjson.o mjson.o
	$(CC) $(CFLAGS) -o test_microjson test_microjson.o mjson.o

# Note: to suppress the footers with timestamps being generated in HTML,
# we use "-a nofooter".
# To debug asciidoc problems, you may need to run "xmllint --nonet --noout --valid"
# on the intermediate XML that throws an error.
.SUFFIXES: .html .adoc .1

.adoc.1:
	asciidoctor -D. -a nofooter -b manpage $<
.adoc.html:
	asciidoctor -D. -a nofooter -a webfonts! $<

# Regression test
check: test_microjson
	./test_microjson

# Worked examples.  These are essentially subsets of the regression test.
example1: example1.c mjson.c mjson.h
example2: example2.c mjson.c mjson.h
example3: example3.c mjson.c mjson.h
example4: example4.c mjson.c mjson.h

clean:
	rm -f *.o *.html test_microjson example[1234]

version:
	@echo $(VERSION)

reflow:
	@clang-format --style="{IndentWidth: 8, UseTab: ForIndentation}" -i mjson.c

SUPPRESSIONS = --suppress=unusedStructMember --suppress=unreadVariable
SUPPRESSIONS += -U__UNUSED__
cppcheck:
	cppcheck -I. --template gcc --enable=all $(SUPPRESSIONS) *.[ch]

SOURCES = Makefile *.[ch]
DOCS = README.adoc COPYING NEWS.adoc control microjson.adoc mjson.adoc
ALL =  $(SOURCES) $(DOCS)
microjson-$(VERSION).tar.gz: $(ALL)
	tar --transform='s:^:microjson-$(VERSION)/:' --show-transformed-names -cvzf microjson-$(VERSION).tar.gz $(ALL)

dist: microjson-$(VERSION).tar.gz

release: microjson-$(VERSION).tar.gz microjson.html mjson.html
	shipper version=$(VERSION) | sh -e -x

refresh: microjson.html mjson.html
	shipper -N -w version=$(VERSION) | sh -e -x
