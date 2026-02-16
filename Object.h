// Object.h
#ifndef MEINCUDAPROJEKT_OBJECT_H
#define MEINCUDAPROJEKT_OBJECT_H

#include "Vector.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ObjectArray object_array;

// typedef struct {
//
// }Color;

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
    obj create_andSetValue(const double mass, const double radius, const Vector pos, const Vector vel, const Vector acc);


#ifdef __cplusplus
}
#endif
#endif // MEINCUDAPROJEKT_OBJECT_H
