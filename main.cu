extern "C" {
#include "Object.h"
#include "ObjectArray.h"
#include <stdio.h>
#include "Calc.h"
#include "raylib.h"
}
ObjectArray arr;

void add() {
    object_array_add(&arr,create_andSetValue(1000000,20,create_Value_2D(20.0,10.0),create_Value_2D(0,0),create_Value_2D(0,0)));
    object_array_add(&arr,create_andSetValue(5000000,20,create_Value_2D(10.0,10.0),create_Value_2D(0.0,0),create_Value_2D(0,0)));
}

void start() {
    InitWindow(1000,1000,"Test");
}

int main() {
    arr = object_array_create(100);

    add();
    object_array_print(&arr);

    start();

    for (int i = 0; i < 15;i++) {
        calc_oneTick(&arr,100);
    }

    while (!WindowShouldClose()) {

    }
    object_array_print(&arr);
}