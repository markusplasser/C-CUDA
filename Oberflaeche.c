#include "raylib.h"
#include "Vector.h"
#include "Object.h"
#include "ObjectArray.h"
#include "Calc.h"



Vector* calc_Position(object_array *arr) {

}


void start(struct ObjectArray *arr, int time_step) {
    InitWindow(1000, 1000, "Test");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {


        BeginDrawing();
        ClearBackground(GRAY);

        double y_middle = 0;
        double x_middle = 0;
        double max_y = 0;
        double max_x = 0;
        double max_distance_x = 0;
        double max_distance_y = 0;

        for (int j = 0; j < arr->count; j++) {
            max_x += arr->data[j].pos.data[0];
            max_y += arr->data[j].pos.data[1];
        }
        y_middle = max_y / arr->count;
        x_middle = max_x / arr->count;

        for (int j = 0; j < arr->count; j++) {
            if (arr->data[j].pos.data[0] > max_distance_x) {
                max_distance_x = arr->data[j].pos.data[0] - x_middle;
            }

            if (arr->data[j].pos.data[1] > max_distance_y) {
                max_distance_y = arr->data[j].pos.data[1] - y_middle;
            }
        }
        if (max_distance_x < 0) {
            max_distance_x *= -1;
        }
        if (max_distance_y < 0) {
            max_distance_y *= -1;
        }
        double max_distance = max_distance_x > max_distance_y ? max_distance_x : max_distance_y;

        for (int j = 0; j < arr->count; j++) {
            double factor = max_distance / arr->data[j].pos.data[0];
            double x_offset = factor * 400;
            double pos_x = 500 + x_offset;

            factor = max_distance / arr->data[j].pos.data[1];
            double y_offset = factor * 400;
            double pos_y = 500 + y_offset;


            DrawCircle(pos_x, pos_y, arr->data[j].radius, RED);

        }


        for (int i = 0; i < time_step; i++) {
            calc_oneTick(arr, 10);
        }
        EndDrawing();
    }
    CloseWindow();
}

