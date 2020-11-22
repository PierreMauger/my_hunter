/*
** EPITECH PROJECT, 2020
** Base
** File description:
** Entity 2
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

float spawn_entity(game_t *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->spawn = game->time.microseconds / 1000000.0;
    if (game->spawn > 0.2 && rand()%8 == 7) {
        create_entity(&game->entity, game->w_size);
    }
    return game->spawn;
}

void replace_entity(entity_t *entity)
{
    entity->name = entity->next->name;
    entity->pos = entity->next->pos;
    entity->speed = entity->next->speed;
    entity->rect = entity->next->rect;
    sfTexture_destroy(entity->texture);
    sfSprite_destroy(entity->sprite);
    entity->texture = entity->next->texture;
    entity->sprite = entity->next->sprite;
    entity->next = entity->next->next;
}
