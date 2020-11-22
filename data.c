/*
** EPITECH PROJECT, 2020
** Base
** File description:
** Data
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my_hunter.h"

sfText *set_text(sfText *temp, data_t *data, sfColor color)
{
    temp = sfText_create();
    sfText_setString(temp, data->str);
    sfText_setFont(temp, data->font);
    sfText_setCharacterSize(temp, 50);
    sfText_setColor(temp, color);
    return temp;
}

void init_data(data_t **temp)
{
    data_t *data = *temp;

    data->str = malloc(5);
    data->font = sfFont_createFromFile("ressources/font");
    data->life = 3;
    data->life_text = set_text(data->life_text, data, sfRed);
    sfText_setPosition(data->life_text, (sfVector2f){100, 100});
    data->score = 0;
    data->score_text = set_text(data->score_text, data, sfYellow);
    sfText_setPosition(data->score_text, (sfVector2f){100, 150});
}

void draw_text(game_t *game)
{
    char l[8] = "Life : ";
    char s[9] = "Score : ";

    game->data->str = my_strcat(l, my_put_nbr(game->data->life));
    sfText_setString(game->data->life_text, game->data->str);
    game->data->str = my_strcat(s, my_put_nbr(game->data->score));
    sfText_setString(game->data->score_text, game->data->str);
    sfRenderWindow_drawText(game->window, game->data->score_text, NULL);
    sfRenderWindow_drawText(game->window, game->data->life_text, NULL);
}
