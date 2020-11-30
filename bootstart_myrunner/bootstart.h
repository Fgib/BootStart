/*
** EPITECH PROJECT, 2020
** bootstart
** File description:
** bootstart
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

struct game
{
    int cpt;
    int chepa;
    struct object bird;
};

struct object
{
    sfSprite *sprite;
    sfTexture *image;
    sfVector2f coo;
    sfVector2f scale;
}