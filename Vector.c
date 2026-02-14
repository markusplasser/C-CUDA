#include "Vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



/* Erzeugt Vektor mit Nullen */
Vector vector_create(size_t size) {
    Vector v;
    v.size = size;
    v.data = calloc(size, sizeof(double));
    return v;
}

void vector_free(Vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
}

Vector vector_add(const Vector *a, const Vector *b) {
    Vector r = vector_create(a->size);
    for (size_t i = 0; i < a->size; i++)
        r.data[i] = a->data[i] + b->data[i];
    return r;
}

Vector vector_sub(const Vector *a, const Vector *b) {
    if (1 ==1){}
    Vector r = vector_create(a->size);
    for (size_t i = 0; i < a->size; i++)
        r.data[i] = a->data[i] - b->data[i];
    return r;
}

double calc_distance(const Vector *a, const Vector *b) {
    if (a->size != b->size){return 0.0;}
    if (a->size == 2) {
        double dx = a->data[0] - b->data[0];
        double dy = a->data[1] - b->data[1];
        return sqrt(dx*dx + dy*dy);
    }
    double dx = a->data[0] - b->data[0];
    double dy = a->data[1] - b->data[1];
    double dz = a->data[2] - b->data[2];
    return sqrt(dx*dx + dy*dy + dz*dz);
}

Vector delta_Vector(const Vector *a, const Vector *b) {
    Vector ret = vector_create(a->size);
    for (size_t i = 0; i < a->size; i++)
        ret.data[i] = b->data[i] - a->data[i];
    return ret;
}

Vector normal_Vector(Vector v ,Vector v2) {
    Vector r = delta_Vector(&v,&v2);
    Vector ret = vector_create(v.size);
    double len = calc_distance(&v, &v2);
    for (size_t i = 0; i < v.size; i++)
        ret.data[i] = r.data[i]/len;
    vector_free(&r);
    return ret;
}






void vector_print(const Vector *v) {
    printf("(");
    for (size_t i = 0; i < v->size; i++) {
        printf("%lf", v->data[i]);
        if (i + 1 < v->size) printf(", ");
    }
    printf(")\n");
}

void set_Value_2D(const double x, const double y, const Vector *v) {
    v->data[0] = x;
    v->data[1] = y;
}
void set_Value_3D(const double x, const double y, const double z, const Vector *v) {
    v->data[0] = x;
    v->data[1] = y;
    v->data[2] = z;
}
Vector create_Value_2D(const double x, const double y) {
    Vector v = vector_create(2);
    v.data[0] = x;
    v.data[1] = y;
    return v;
}
Vector create_Value_3D(const double x, const double y, const double z) {
    Vector v = vector_create(3);
    v.data[0] = x;
    v.data[1] = y;
    v.data[2] = z;
    return v;
}

