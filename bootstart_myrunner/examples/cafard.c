/*
** EPITECH PROJECT, 2020
** graphical_CSFML
** File description:
** main.c
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

sfRenderWindow *create_my_window(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "My_hunter", \
sfTitlebar | sfClose, NULL);
    return (window);
}

void manage_animation(sfSprite *sprite, int i)
{
    sfIntRect rekt;
    rekt.top = (i / 8) * 310;
    rekt.left = (i % 8) * 398;
    rekt.height = 310;
    rekt.width = 398;
    sfSprite_setTextureRect(sprite, rekt);
}

int main(void)
{
    sfRenderWindow *window = create_my_window(800, 600);
    sfClock *var_temp = sfClock_create();
    sfEvent event;
    sfTexture *texture;
    sfSprite *dot = sfSprite_create();
    int i = 0;

    sfVector2f scale;
    scale.x = 2;
    scale.y = 2;

    texture = sfTexture_createFromFile("pics/hr-biter-run-01.png", NULL);
    sfSprite_setTexture(dot, texture, sfTrue);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed)
                printf("x= %d\ty= %d\n", event.mouseButton.x, event.mouseButton.y);
        }
        if (sfClock_getElapsedTime(var_temp).microseconds > 41667) {
            i += i < 63 ? 1 : -63;
            manage_animation(dot, i);
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawSprite(window, dot, NULL);
            sfSprite_setScale(dot, scale);
            sfRenderWindow_display(window);
            sfClock_restart(var_temp);
        }
    }
    sfRenderWindow_destroy(window);
}