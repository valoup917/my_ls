/*
** EPITECH PROJECT, 2021
** ls d
** File description:
** .
*/

#include "../include/my_ls.h"

void dumb_d(void);

void my_d(char *file)
{
    DIR *dir;

    if (file == NULL)
        file = ".";
    dir = open_my_dir(file);
    dumb_d();

    closedir(dir);
}

void dumb_d(void)
{
    my_putstr(".");
    my_putchar('\n');
}