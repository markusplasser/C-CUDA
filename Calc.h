//
// Created by Spieler on 14.02.2026.
//

#ifndef MEINCUDAPROJEKT_CALC_H
#define MEINCUDAPROJEKT_CALC_H


void calc_oneTick(ObjectArray *arr,double dt);
void durchschnitt(ObjectArray *arr,int id);
Vector calc_force(const obj *a, const obj *b);
#endif //MEINCUDAPROJEKT_CALC_H
