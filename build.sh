gcc -c microjson-1.7/mjson.c -o mjson.o
ar rcs libmjson.a mjson.o

gcc -c idioticjson.c -o idioticjson.o
ar rcs libidioticjson.a idioticjson.o mjson.o

# Compile and link the example program with static libraries
gcc example.c -static -L. -lidioticjson -o example

# Delete the object file
rm mjson.o
rm idioticjson.o
# rm *.a # maybe if you want to delete this too
