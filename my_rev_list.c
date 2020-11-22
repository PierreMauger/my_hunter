/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** 5 cute functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my_hunter.h"

void my_rev_list(entity_t **begin)
{
    entity_t *actual = *begin;
    entity_t *previous = NULL;
    entity_t *next = NULL;

    while (actual != NULL) {
        next = actual->next;
        actual->next = previous;
        previous = actual;
        actual = next;
    }
    *begin = previous;
}

int my_strlen(char const *str)
{
    int i = 0;

    for (;str[i] != '\0' && str[i] != '\n'; i++);
    return (i);
}

char *my_strcat(char *dest, char const *src)
{
    int m = my_strlen(dest);

    for (int i = 0; src[i] != '\0'; i++) {
        dest[m + i] = src[i];
        dest[m + i + 1] = '\0';
    }
    return (dest);
}

char *my_revstr(char *str)
{
    int j = my_strlen(str) - 1;
    char c;

    for (int i = 0; i < my_strlen(str) / 2; i++) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        j--;
    }
    return (str);
}

char *my_put_nbr(int nb)
{
    int i = nb;
    int j;
    char *res = malloc(5);
    res[0] = '0';
    res[1] = '\0';

    for (int c = 0; i != 0; c++) {
        j = i % 10;
        i = i / 10;
        res[c] = j + '0';
        res[c + 1] = '\0';
    }
    return my_revstr(res);
}
