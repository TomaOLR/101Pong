/*
** EPITECH PROJECT, 2019
** test.c
** File description:
** Thomas Olry's test.c made the 11/08/2019
*/

#include "../include/pong.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


pong_t *velocity_vector(float xA, float yA, float zA, float x, float y, float z)
{
    pong_t *pong = malloc(sizeof(pong));
    pong->x = (xA - x) * -1;
    pong->y = (yA - y) * -1;
    pong->z = (zA - z) * -1;

    return (pong);
}

float norm_of_vector(float x, float y, float z)
{
    return (sqrtf((x * x) + (y * y) + (z * z)));
}

float pos(float v, float pt, float n)
{
    return ((v * n) + v + pt);
}

float calcul_angle(pong_t *pong)
{
    float norm = norm_of_vector(pong->x, pong->y, pong->z);
    float res = asinf(pong->z / norm);

    return (((res * 180) / M_PI) * -1);
}

int pong_math(float xa, float ya, float za, float xb, float yb, float zb, float n)
{
    pong_t *pong = velocity_vector(xa, ya, za, xb, yb, zb);

    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n", pong->x, pong->y, pong->z);
    printf("At time t + %.0f, ball coordinates will be:\n", n);
    printf("(%.2f, %.2f, %.2f)\n", pos(pong->x, xa, n), pos(pong->y, ya, n), pos(pong->z, za, n));
    if (-zb/(zb - za) < 0)
        printf("The ball won't reach the paddle.\n");
    else {
        printf("The incidence angle is:\n");
        printf("%.2f degrees\n", calcul_angle(pong));
    }
}

int main(int ac, char **av)
{
    if (ac != 8)
        return (84);
    float xa = atof(av[1]);
    float ya = atof(av[2]);
    float za = atof(av[3]);
    float xb = atof(av[4]);
    float yb = atof(av[5]);
    float zb = atof(av[6]);
    int n = atoi(av[7]);

    if (n < 0)
        return (84);
    pong_math(xa, ya, za, xb, yb, zb, n);
    return (0);
}
