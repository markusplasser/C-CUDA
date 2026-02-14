#include "Vector.h"
#include "Object.h"
#include "Math.h"
#include "ObjectArray.h"

const double G = 6.6743e-11;

Vector calc_force(const obj *a, const obj *b) {
    Vector r = vector_create(a->vel.size);
    Vector normal =  normal_Vector(a->pos,b->pos);

    for (size_t i = 0; i < a->vel.size; i++)
        r.data[i] = G * a->mass/ pow(calc_distance(&a->pos,&b->pos),2)*normal.data[i];
    return r;
}



void durchschnitt(struct ObjectArray *arr, const int id) {
    if (arr->count == 0) {
        return;
    }
    for (int i = 0; i < arr->count; i++) {
        if (arr->data[i].ID == id) continue;
        const Vector force  = calc_force(object_array_get(arr,id),&arr->data[i]);
        for (int j = 0; j < arr->data[i].vel.size; j++) {
            arr->data[id].acc.data[j] += force.data[j];
        }
    }
}

void calc_oneTick(struct ObjectArray *arr,double dt) {
    /**
     * Erste halbe berchnung der Vel
     * Danch wird die Vel direkt geupdated
     **/
    for (size_t i = 0; i < arr->count; i++) {
        for (int j = 0; j < arr->data[i].vel.size; j++) {
            arr->data[i].vel.data[j] += arr->data[i].acc.data[j]*dt/2;
        }
    }

    /**
     *Update Pos
     *Pos = pos + vel * dt
     **/
    for (int i = 0; i < arr->count; i++) {
        arr->data[i].pos.data[0] = arr->data[i].pos.data[0] + arr->data[i].vel.data[0]*dt;
        arr->data[i].pos.data[1] = arr->data[i].pos.data[1] + arr->data[i].vel.data[1]*dt;
    }

    /**
     * Clac Acc for each Objekt
     **/
    for (int i = 0; i < arr->count; i++) {
        for (int j = 0; j < arr->data[i].acc.size; j++) {
            arr->data[i].acc.data[j] = 0;
        }
        durchschnitt(arr,arr->data[i].ID);
    }

    /**
     *Zweite Hälfte von der Vel
     **/
    for (size_t i = 0; i < arr->count; i++) {
        for (int j = 0; j < arr->data[i].vel.size; j++) {
            arr->data[i].vel.data[j] += arr->data[i].acc.data[j]*dt/2;
        }
    }
}
