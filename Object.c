#include "Vector.h"
#include "Object.h"
#include "stdio.h"
#include "Math.h"
#include "ObjectArray.h"


static int IDcounter = 0;
const double G = 6.6743e-11;

obj createObjectZero() {
    obj obj;
    obj.ID = IDcounter++;
    obj.mass = 0.000000000000000000000000000;
    obj.radius = 0.0;
    obj.pos = vector_create(0);
    obj.vel = vector_create(0);
    obj.acc = vector_create(0);
    return obj;
}


void setValuesToObject(obj *obj, const double mass, const double radius, const Vector pos, const Vector vel, const Vector acc) {
    obj->mass = mass;
    obj->radius = radius;
    obj->pos = pos;
    obj->vel = vel;
    obj->acc = acc;
}

obj create_andSetValue(const double mass, const double radius, const Vector pos, const Vector vel, const Vector acc) {
    obj obj = createObjectZero();
    obj.mass = mass;
    obj.radius = radius;
    obj.pos.data[0] = pos.data[0];
    obj.pos.data[1] = pos.data[1];
    obj.vel = vel;
    obj.acc = acc;
    return obj;
}

void printObj(obj *obj) {
    printf("Info von Object{\n ID: %d\n MASS: %lf\n Radius: %lf\n Pos:  X=%lf,Y=%lf\n Vel: X=%lf,Y=%lf\n Acc: X=%lf,Y=%lf}\n",obj->ID,obj->mass,obj->radius,obj->pos.data[0],obj->pos.data[1],obj->vel.data[0],obj->vel.data[1],obj->acc.data[0],obj->acc.data[1]);
}

Vector calc_force(const obj *a, const obj *b) {
    Vector r;
    Vector normal = vector_create(a->vel.size);
    normal = normal_Vector(a->vel,b->vel);
    r = vector_create(a->vel.size);
    for (size_t i = 0; i < a->vel.size; i++)
        r.data[i] = G * a->mass/ pow(calc_distance(&a->pos,&b->pos),2)*normal.data[i];
    return r;
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

void durchschnitt(object_array *arr, const int id) {
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