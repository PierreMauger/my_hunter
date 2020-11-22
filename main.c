/*
** EPITECH PROJECT, 2020
** Base
** File description:
** Main
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my_hunter.h"

int main(int argc, char **argv)
{
    srand(time(NULL));
    if (argc == 2)
        if (argv[1][0] == '-' || argv[1][1] == 'h') {
            write(1, "a super duckhunt game where you can finally hunt a", 51);
            write(1, "ll the Pidgey you ever dreamed of !\n\nCONTROLS : ", 49);
            write(1, "mouseclick = shoot\n           alt+F4 : close game", 50);
            write(1, "\n           any other touch : spawn a Pidgey\n", 46);
            return 0;
        }
    hunter();
    return 0;
}
