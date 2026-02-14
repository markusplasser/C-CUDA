

#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"
#include "ObjectArray.h"





object_array object_array_create(size_t capacity) {
    object_array arr;
    arr.count = 0;
    arr.capacity = capacity;
    arr.data = (obj*)malloc(capacity * sizeof(obj));
    return arr;
}

// --- Add ---
int object_array_add(object_array *arr, obj obj) {
    // 1. Sicherheitscheck: Existiert das Array überhaupt?
    if (arr == NULL || arr->data == NULL) {
        return -2;
    }

    // 2. Kapazitätscheck
    if (arr->count >= arr->capacity) {
        return -1;
    }

    // 3. Hinzufügen
    arr->data[arr->count] = obj;
    arr->count++;

    return 0;
}

// --- Get by ID ---
obj* object_array_get(object_array *arr, int id) {
    for (size_t i = 0; i < arr->count; i++) {
        if (arr->data[i].ID == id)
            return &arr->data[i];
    }
    return NULL;
}

// --- Remove by ID ---
int object_array_remove(object_array* arr, int id) {
    for (size_t i = 0; i < arr->count; i++) {
        if (arr->data[i].ID == id) {
            // Speicher der Vektoren freigeben
            vector_free(&arr->data[i].pos);
            vector_free(&arr->data[i].vel);
            vector_free(&arr->data[i].acc);

            // Letztes Element nachrücken lassen → O(1) Delete
            arr->data[i] = arr->data[arr->count - 1];
            arr->count--;
            return 0; // Erfolg
        }
    }
    return -1; // nicht gefunden
}

// --- Print all ---
void object_array_print(const object_array* arr) {
    printf("ObjectArray (%zu objects)\n", arr->count);
    for (size_t i = 0; i < arr->count; i++) {

        printf("ID: %d | Mass: %.2lf | Radius: %2.lf  | Pos: X=%.2lf,Y=%.2lf | Vel: X=%.2lf,Y=%.2lf | Acc: X=%.2lf,Y=%.2lf\n",
               arr->data[i].ID,
               arr->data[i].mass,
               arr->data[i].radius,
               arr->data[i].pos.data[0],
               arr->data[i].pos.data[1],
               arr->data[i].vel.data[0],
               arr->data[i].vel.data[1],
               arr->data[i].acc.data[0],
               arr->data[i].acc.data[1]);
    }
}

// --- Free all ---
void object_array_free(object_array* arr) {
    for (size_t i = 0; i < arr->count; i++) {
        vector_free(&arr->data[i].pos);
        vector_free(&arr->data[i].vel);
        vector_free(&arr->data[i].acc);
    }
    free(arr->data);
    arr->data = NULL;
    arr->count = 0;
    arr->capacity = 0;
}
