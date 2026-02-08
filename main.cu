extern "C" {
#include "Object.h"
#include "ObjectArray.h"
#include <stdio.h>
}

ObjectArray arr;



int main() {
    printf("Hello World!\n");
    arr = object_array_create(100);
    object_array_add(&arr,create_andSetValue(10000,20,create_Value_2D(50000000000000,5.0),create_Value_2D(5.0,0),create_Value_2D(0,0)));
    object_array_add(&arr,create_andSetValue(10000,20,create_Value_2D(10.0,10.0),create_Value_2D(0.0,0),create_Value_2D(0,0)));

    for (int i = 0; i < 1000;i++) {
        calc_oneTick(&arr,0.01);
    }

    object_array_print(&arr);
}