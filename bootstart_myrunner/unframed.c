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
    rekt.top = 0;
    rekt.left = i * 110;
    rekt.height = 110;
    rekt.width = 110;

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
    int cpt = 0;
    sfVector2f coo;

    texture = sfTexture_createFromFile("bird_spritesheet.png", NULL);
    sfSprite_setTexture(dot, texture, sfTrue);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed)
                printf("x= %d\ty= %d\n", event.mouseButton.x, event.mouseButton.y);
        }
        cpt++;
        i += i < 3 ? 1 : -3;
        manage_animation(dot, i);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, dot, NULL);
        coo.x = 5;
        coo.y = 3;
        sfSprite_setPosition(dot, coo);
        sfRenderWindow_display(window);
        sfClock_restart(var_temp);
    }
    printf("%d\n", cpt);
    sfRenderWindow_destroy(window);
}