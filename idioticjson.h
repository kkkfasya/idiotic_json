// TODO: Make this stb-style lib
// WARNING: don't use this lib

#ifndef IDIOTICJSON_H_
#define IDIOTICJSON_H_

#include "microjson-1.7/mjson.h"

typedef struct json_attr_t Json_Attr;

extern Json_Attr *idiotic_start(size_t size);
extern void idiotic_append_str_attr(Json_Attr *attr, char *attr_name, char *addr, size_t len);
extern void idiotic_append_bool_attr(Json_Attr *attr, char *attr_name, bool *addr);
extern void idiotic_append_int_attr(Json_Attr *attr, char *attr_name, int *addr);
extern void idiotic_end(Json_Attr *attr);
/* Parse the json string to the given struct
 * this function also automatically freed the pointer *attr  
 * return 1 if error occurs */
extern int idiotic_parse(const char *json_str, Json_Attr *attr);

#endif // IDIOTICJSON_H_
