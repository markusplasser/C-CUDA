#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    size_t size;   // Dimension des Vektors
    double *data;  // Komponenten
} Vector;

/* Erzeugung & Speicher */
Vector vector_create(size_t size);
void  vector_free(Vector *v);

/* Basis-Operationen */
Vector vector_add(const Vector *a, const Vector *b);
Vector vector_sub(const Vector *a, const Vector *b);
Vector vector_scale(const Vector *v, double scalar);

/* Mathe */
double vector_dot(const Vector *a, const Vector *b);
double vector_length(const Vector *v);
Vector vector_normalize(const Vector *v);

/* Utility */
void vector_print(const Vector *v);

//Set_Value

void set_Value_2D(const double x,const double y,const Vector *v);
void set_Value_3D(const double x,const double y,const double z,const Vector *v);
double calc_distance(const Vector *a, const Vector *b);
Vector normal_Vector(Vector v ,Vector v2);
Vector create_Value_2D(const double x, const double y);
Vector create_Value_3D(const double x, const double y, const double z);

#ifdef __cplusplus
}
#endif

#endif // VECTOR_H