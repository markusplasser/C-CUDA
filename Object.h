// Object.h
#ifndef MEINCUDAPROJEKT_OBJECT_H
#define MEINCUDAPROJEKT_OBJECT_H

#include "Vector.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ObjectArray object_array;

typedef struct {
        int ID;
        double mass;
        double radius;
        Vector pos;
        Vector vel;
        Vector acc;
    } obj;

    obj createObjectZero();
    void setValuesToObject(obj *obj,  double mass, double radius, Vector pos, Vector vel, Vector acc);
    void printObj(obj *obj);
    void durchschnitt(struct ObjectArray *arr,int id);
    obj create_andSetValue(const double mass, const double radius, const Vector pos, const Vector vel, const Vector acc);
    void calc_oneTick(struct ObjectArray *arr,double dt);

#ifdef __cplusplus
}
#endif
#endif // MEINCUDAPROJEKT_OBJECT_H
