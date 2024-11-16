# IDIOTICJSON
My idiotic attempt at wrapping the microjson libary

## Usage
```c
// example.c
#include <stdio.h>
#include <stdbool.h>
#include "idioticjson.h"

int main(int argc, char **argv) {
    typedef struct {
        char text[20];
        bool boolean;
        int number;
    } Obj;

    Obj obj;
    Json_Attr *attr = idiotic_start(sizeof(Obj)); // init this idiotic lib
    idiotic_append_str_attr(attr, "text", obj.text, sizeof(obj.text)); // idiotic_append_<DATA_TYPE>_attr
    idiotic_append_bool_attr(attr, "boolean", &(obj.boolean));
    idiotic_append_int_attr(attr, "number", &(obj.number));
    idiotic_end(attr);
    idiotic_parse(argv[1], attr); // after being parsed, it's being freed automatically

    printf("text    : %s\n", obj.text);
    printf("number  : %d\n", obj.number);
    printf("boolean : %s\n", obj.boolean ? "true" : "false");
    return 0;
}

```
Then compile it & run it
```sh
$ chmod +x ./build.sh
$ ./build.sh
$ ./example '{"text": "sample message", "boolean": true, "number": 5}'
```

#### WARNING: currently only support 3 data type
> Don't use this lib please
