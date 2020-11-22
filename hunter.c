/*
** EPITECH PROJECT, 2020
** Base
** File description:
** Hunter
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

entity_t *check_collide(game_t *game)
{
    entity_t *entity = game->entity;

    game->position = sfMouse_getPositionRenderWindow(game->window);
    while (entity != NULL) {
        entity->pos = sfSprite_getPosition(entity->sprite);
        if (game->position.x >= entity->pos.x && game->position.x <=
        entity->pos.x + 110 && game->position.y >= entity->pos.y &&
        game->position.y <= entity->pos.y + 110) {
            game->data->score += 1;
            sfSound_setBuffer(game->sound, game->soundbuffer);
            sfSound_play(game->sound);  
            if (entity->next != NULL)
                replace_entity(entity);
            else {
                my_rev_list(&game->entity);
                return game->entity->next;
            }
        }
        entity = entity->next;
    }
    return game->entity;
}

entity_t *check_collide_wall(game_t *game)
{
    entity_t *entity = game->entity;

    while (entity != NULL) {
        entity->pos = sfSprite_getPosition(entity->sprite);
        if (entity->pos.x > game->w_size.width && entity->speed.x >= 1 ||
        entity->pos.x < -110 && entity->speed.x <= -1) {
            game->data->life -= 1;
            if (entity->next != NULL)
                replace_entity(entity);
            else {
                my_rev_list(&game->entity);
                return game->entity->next;
            }
        }
        if (entity->pos.y + 114 > game->w_size.height || entity->pos.y < 0)
            entity->speed.y *= -1;
        entity = entity->next;
    }
    return game->entity;
}

void event_loop(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfSound_setBuffer(game->sounds, game->soundshot);
            sfSound_setVolume(game->sounds, (float)25);
            sfSound_play(game->sounds);
            game->entity = check_collide(game);
        }
        if (game->event.type == sfEvtKeyPressed)
            create_entity(&game->entity, game->w_size);
    }
}

void draw_bg(game_t *game)
{
    sfSprite_setTexture(game->bgs, game->bgt, sfTrue);
    sfSprite_setScale(game->bgs, (sfVector2f){(float)game->w_size.width/1920,
    (float)game->w_size.height/1017});
    sfRenderWindow_drawSprite(game->window, game->bgs, NULL);
}

void hunter(void)
{
    game_t *game = malloc(sizeof(game_t));

    init_game(&game);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        draw_bg(game);
        draw_entity(game->entity, game->window);
        draw_text(game);
        game->entity = check_collide_wall(game);
        game->spawn = spawn_entity(game);
        game->seconds = anim_entity(game);
        event_loop(game);
        sfRenderWindow_display(game->window);
        if (game->data->life <= 0)
            sfRenderWindow_close(game->window);
    }
    destroy_all(game);
}