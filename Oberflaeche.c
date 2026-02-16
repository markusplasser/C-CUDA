#include "raylib.h"
#include "Vector.h"
#include "Object.h"
#include "ObjectArray.h"
#include "Calc.h"


void start(struct ObjectArray *arr,int time_step) {
    InitWindow(1000,1000,"Test");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int i = 0; i < arr->count; i++) {
            DrawCircle(arr->data[i].pos.data[0],arr->data[i].pos.data[1],arr->data[i].radius,RED);
        }
        for (int i = 0; i < time_step; i++) {
            calc_oneTick(arr,10);
        }
        EndDrawing();
    }
}