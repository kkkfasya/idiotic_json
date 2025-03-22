#!/bin/bash

# Compile & link the libs
gcc -c microjson-1.7/mjson.c -o mjson.o
ar rcs libmjson.a mjson.o

gcc -c idioticjson.c -o idioticjson.o
ar rcs libidioticjson.a idioticjson.o mjson.o

# Compile
# gcc example.c -L. -lidioticjson -o example

# Statically link lidioticjson, then the rest are dynamically linked
gcc example.c -L. -Wl,-Bstatic -lidioticjson -Wl,-Bdynamic -o example

# Delete the object file
 rm mjson.o
 rm idioticjson.o
# rm *.a # maybe if you want to delete this too
