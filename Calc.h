//
// Created by Spieler on 14.02.2026.
//


#ifdef __cplusplus
extern "C" {
#endif

#ifndef MEINCUDAPROJEKT_CALC_H
#define MEINCUDAPROJEKT_CALC_H


Vector calc_force(const obj *a, const obj *b);
void durchschnitt(struct ObjectArray *arr,int id);
void calc_oneTick(struct ObjectArray *arr,double dt);


#ifdef __cplusplus
}
#endif
#endif //MEINCUDAPROJEKT_CALC_H
