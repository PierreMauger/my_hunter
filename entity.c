/*
** EPITECH PROJECT, 2020
** Base
** File description:
** Entity 1
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

void move_rect(sfIntRect *rect, int offset, int max_offset)
{
    rect->left += offset;
    if (rect->left >= max_offset)
        rect->left = 0;
}

void create_entity(entity_t **list, sfVideoMode w_size)
{
    entity_t *entity = malloc(sizeof(entity_t));
    int random_y = rand()%(w_size.height - 110);
    int side = rand()%2;

    entity->pos = (sfVector2f){0, random_y};
    entity->speed = (sfVector2f){4, rand()%5 - 2};
    entity->rect = (sfIntRect){0, 0, 120, 114};
    entity->texture = (sfTexture *)sfTexture_createFromFile
    ("ressources/pidgey.png", NULL);
    entity->sprite = (sfSprite *)sfSprite_create();
    entity->name = "lol";
    sfSprite_setPosition(entity->sprite, (sfVector2f){0, random_y});
    if (side == 1) {
        entity->speed = (sfVector2f){-4, rand()%3 - 1};
        sfSprite_scale(entity->sprite, (sfVector2f){-1, 1});
        sfSprite_setOrigin(entity->sprite, (sfVector2f){110, 0});
        sfSprite_setPosition(entity->sprite, (sfVector2f){w_size.width - 110,
        random_y});
    }
    entity->next = *list;
    *list = entity;
}

void draw_entity(entity_t *entity, sfRenderWindow *window)
{
    while (entity != NULL) {
        sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
        sfSprite_setTextureRect(entity->sprite, entity->rect);
        sfRenderWindow_drawSprite(window, entity->sprite, NULL);
        sfSprite_move(entity->sprite, entity->speed);
        entity = entity->next;
    }
}

float anim_entity(game_t *game)
{
    entity_t *temp = game->entity;

    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    if (game->seconds > 0.2) {
        while (temp != NULL) {
            move_rect(&temp->rect, 120, 480);
            temp = temp->next;
        }
        sfClock_restart(game->clock);
    }
    return game->seconds;
}

void destroy_entity(entity_t *entity)
{
    while (entity != NULL) {
        sfTexture_destroy(entity->texture);
        sfSprite_destroy(entity->sprite);
        entity = entity->next;
    }
}
