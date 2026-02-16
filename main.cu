extern "C" {
#include "Object.h"
#include "ObjectArray.h"
#include <stdio.h>
#include "Calc.h"
#include "raylib.h"
#include "Oberflaeche.h"
}
ObjectArray arr;

void add() {
    object_array_add(&arr,create_andSetValue(20000000,20,create_Value_2D(300.0,700.0),create_Value_2D(0,0.001),create_Value_2D(0,0)));
    object_array_add(&arr,create_andSetValue(10000000,20,create_Value_2D(800.0,600.0),create_Value_2D(0,-0.001),create_Value_2D(0,0)));
    //object_array_add(&arr,create_andSetValue(10000000,20,create_Value_2D(400.0,220.0),create_Value_2D(0,-0.001),create_Value_2D(0,0)));
}


int main() {
    arr = object_array_create(100);

    add();
    object_array_print(&arr);

    start(&arr,2000);

    object_array_print(&arr);
}