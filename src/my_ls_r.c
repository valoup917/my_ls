/*
** EPITECH PROJECT, 2021
** ls r
** File description:
** .
*/

#include "../include/my_ls.h"

void reverse_all(char **sort_table);

void my_r(char *file)
{
    char **tab;
    DIR *dir;

    if (file == NULL)
        file = ".";
    dir = open_my_dir(file);
    tab = fill_the_tab(dir);
    reverse_all(tab);
    closedir(dir);
}

void reverse_all(char **sort_table)
{
    sort_table = my_revstr(sort_table);
    int compteur = 0;
    for (int i = 1;sort_table[i] != NULL; i++)
        if (sort_table[i][0] != '.')
            compteur++;
    for (int i = 1;sort_table[i] != NULL;i++) {
        if (i == compteur && sort_table[i][0] != '.') {
            my_putstr(sort_table[i]);
            my_putchar('\n');
            return;
        }
        if (sort_table[i][0] != '.')
            my_putstr(sort_table[i]), my_putstr("  ");
    }
    return;
}