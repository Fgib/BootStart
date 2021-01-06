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

void animation(sfSprite *dot, int cpt)
{
    sfIntRect rekt;
    rekt.height = 110;
    rekt.width = 110;
    rekt.top = 0;
    rekt.left = cpt * 110;
    sfSprite_setTextureRect(dot, rekt);
}

int main(void)
{
    sfRenderWindow *window = create_my_window(1200, 800);
    sfEvent event;
    sfClock *time;

    sfSprite *dot = sfSprite_create();
    sfTexture *image = sfTexture_createFromFile("bird_spritesheet.png", NULL);

    sfSprite_setTexture(dot, image, sfTrue);

    sfVector2f coo;
    sfVector2f coo2;
 
    int cpt = 0;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        if (sfClock_getElapsedTime(time).microseconds > 41667) {
            if (cpt < 3)
                cpt++;
            else 
                cpt = 0;
            sfRenderWindow_clear(window, sfBlack);
            animation(dot, cpt);
            coo.x = 150;
            coo.y = 150;
            sfRenderWindow_drawSprite(window, dot, NULL);
            sfSprite_setPosition(dot, coo);
            sfSprite_setRotation(dot, 45 * cpt);
            sfRenderWindow_display(window);
            sfClock_restart(time);
        }
    }
}