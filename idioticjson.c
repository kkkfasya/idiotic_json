#include <stdio.h>
#include <stdlib.h>
#include "idioticjson.h"

static int count = 0; // counter for index n shit

Json_Attr *idiotic_start(size_t size) {
    count = 0; // reset count
    Json_Attr *ptr =  (Json_Attr *) malloc(size * 1.3); // just in case yk
    if (ptr == NULL) {
        fprintf(stderr, "[ERROR]: FAILED TO ALLOCATE MEMORY\n");
        return NULL;
    }
    return ptr;
}

void idiotic_append_str_attr(Json_Attr *attr, char *attr_name, char *addr, size_t len) {
    attr[count].attribute = attr_name;
    attr[count].type = t_string;
    attr[count].addr.string = addr;
    attr[count].len = len;
    count++;
}

void idiotic_append_bool_attr(Json_Attr *attr, char *attr_name, bool *addr) {
    attr[count].attribute = attr_name;
    attr[count].type = t_boolean;
    attr[count].addr.boolean = addr;
    count++;
}
void idiotic_append_int_attr(Json_Attr *attr, char *attr_name, int *addr) {
    attr[count].attribute = attr_name;
    attr[count].type = t_integer;
    attr[count].addr.integer = addr;
    count++;
}

void idiotic_end(Json_Attr *attr) {
    attr[count].attribute = NULL;
    count = 0;
}

int idiotic_parse(const char *json_str, Json_Attr *attr) {
    int status = json_read_object(json_str, attr, NULL);
    if (status != 0) {
        fprintf(stderr, "[ERROR]: %s\n", json_error_string(status));
        return 1;
    }
    free(attr);
    attr = NULL;
    return 0;
}

