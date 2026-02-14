#include "Vector.h"
#include "Object.h"
#include "stdio.h"
#include "Math.h"
#include "ObjectArray.h"


static int IDcounter = 0;


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
    obj.pos = pos;
    obj.vel = vel;
    obj.acc = acc;
    return obj;
}

void printObj(obj *obj) {
    printf("Info von Object{\n ID: %d\n MASS: %lf\n Radius: %lf\n Pos:  X=%lf,Y=%lf\n Vel: X=%lf,Y=%lf\n Acc: X=%lf,Y=%lf}\n",obj->ID,obj->mass,obj->radius,obj->pos.data[0],obj->pos.data[1],obj->vel.data[0],obj->vel.data[1],obj->acc.data[0],obj->acc.data[1]);
}

