/*
** EPITECH PROJECT, 2020
** Base
** File description:
** Game
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my_hunter.h"

sfRenderWindow *create_my_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "my_hunter",
    sfFullscreen, NULL);
    return (window);
}

void init_game(game_t **temp)
{
    game_t *game = *temp;

    game->w_size = sfVideoMode_getDesktopMode();
    game->window = create_my_window(game->w_size.width, game->w_size.height);
    game->position = (sfVector2i){0, 0};
    game->entity = NULL;
    game->clock = sfClock_create();
    game->soundbuffer = sfSoundBuffer_createFromFile("ressources/pidgey.ogg");
    game->soundshot = sfSoundBuffer_createFromFile("ressources/gunshot.wav");
    game->sound = sfSound_create();
    game->sounds = sfSound_create();
    game->data = malloc(sizeof(data_t));
    init_data(&game->data);
    game->bgt = sfTexture_createFromFile("ressources/bg.png", NULL);
    game->bgs = sfSprite_create();
    game->music = sfMusic_createFromFile("ressources/music.ogg");
    sfMusic_play(game->music);
    sfMusic_setLoop(game->music, 1);
}

void destroy_all(game_t *game)
{
    destroy_entity(game->entity);
    sfSoundBuffer_destroy(game->soundbuffer);
    sfSound_destroy(game->sound);
    sfSoundBuffer_destroy(game->soundshot);
    sfSound_destroy(game->sounds);
    sfMusic_pause(game->music);
    sfMusic_stop(game->music);
    sfMusic_destroy(game->music);
    sfRenderWindow_destroy(game->window);
}
