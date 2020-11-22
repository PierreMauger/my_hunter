/*
** EPITECH PROJECT, 2020
** Include
** File description:
** my_hunter
*/

#ifndef HUNTER_H
#define HUNTER_H

typedef struct entity {
    char *name;
    sfVector2f pos;
    sfVector2f speed;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    struct entity *next;
} entity_t;

typedef struct data {
    sfFont *font;
    sfText *life_text;
    sfText *score_text;
    sfText *high_text;
    int life;
    int score;
    int high_score;
    char *str;
} data_t;

typedef struct game {
    sfRenderWindow *window;
    sfVideoMode w_size;
    sfVector2i position;
    sfEvent event;
    entity_t *entity;
    sfClock *clock;
    sfTime time;
    float seconds;
    float spawn;
    data_t *data;
    sfSoundBuffer *soundbuffer;
    sfSoundBuffer *soundshot;
    sfSound *sound;
    sfSound *sounds;
    sfTexture *bgt;
    sfSprite *bgs;
    sfMusic *music;
} game_t;

void move_rect(sfIntRect *rect, int offset, int max_offset);
void create_entity(entity_t **list, sfVideoMode w_size);
void draw_entity(entity_t *entity, sfRenderWindow *window);
float anim_entity(game_t *game);
void destroy_entity(entity_t *entity);
float spawn_entity(game_t *game);
void replace_entity(entity_t *entity);
entity_t *check_collide(game_t *game);
entity_t *check_collide_wall(game_t *game);
void event_loop(game_t *game);
void draw_bg(game_t *game);
void hunter();
sfRenderWindow *create_my_window(unsigned int width, unsigned int height);
void init_game(game_t **temp);
void destroy_all(game_t *game);
sfText *set_text(sfText *temp, data_t *data, sfColor color);
void init_data(data_t **temp);
void draw_text(game_t *game);
void my_rev_list(entity_t **begin);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_put_nbr(int nb);

#endif
