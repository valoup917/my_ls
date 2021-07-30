/*
** EPITECH PROJECT, 2021
** my _ls
** File description:
** .
*/

#include "../include/my_ls.h"

void my_ls(char *file)
{
    char **tab;
    DIR *dir;

    if (file == NULL)
        file = ".";
    dir = open_my_dir(file);
    tab = fill_the_tab(dir);
    print_my_dir(tab);
    closedir(dir);
}

void print_my_dir(char **string)
{
    int i = 0;
    while (string[i]) {
        if (string[i][0] != '.') {
            my_putstr(string[i]);
            my_putstr("  ");
        }
        i++;
    }
    my_putstr("\n");
}