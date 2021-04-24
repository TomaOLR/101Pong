/*
** EPITECH PROJECT, 2019
** pong.h
** File description:
** Thomas Olry's pong.h made the 11/08/2019
*/

#ifndef PONG_H_
#define PONG_H_

#include <math.h>

typedef struct pong_s {
    float x;
    float y;
    float z;
} pong_t;

pong_t *velocity_vector(float xA, float yA, float zA, float x, float y, float z);
float norm_of_vector(float x, float y, float z);
float pos(float v, float pt, float n);
float calcul_angle(pong_t *pong);
int pong_math(float xa, float ya, float za, float xb, float yb, float zb, float n);

#endif /* PONG_H_ */
