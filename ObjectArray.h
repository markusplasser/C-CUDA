#ifndef object_array_H
#define object_array_H

#include "Object.h"
#ifdef __cplusplus
extern "C"
#endif


typedef struct ObjectArray{
    obj* data;
    size_t count;
    size_t capacity;
} object_array;

object_array object_array_create(size_t capacity);
int object_array_add(object_array* arr, obj obj);
obj* object_array_get(object_array* arr, int id);
int object_array_remove(object_array* arr, int id);
void object_array_print(const object_array* arr);
void object_array_free(object_array* arr);

#ifdef __cplusplus

#endif

#endif // object_array_H
