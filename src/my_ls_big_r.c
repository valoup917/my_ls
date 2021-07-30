/*
** EPITECH PROJECT, 2021
** my_ls_R
** File description:
** .
*/

#include "../include/my_ls.h"

void my_recusrive(char **tab, char *file);

void my_big_r(void)
{
    char **tab;
    DIR *dir;

    dir = open_my_dir(".");
    tab = fill_the_tab(dir);
    my_recusrive(tab, NULL);
    closedir(dir);
}

void my_recusrive(char **tab, char *file)
{
    DIR *dir;
    struct stat buf;
    int a = 0;

    for (int i = 0;tab[i];i++) {

        if ((a = stat(tab[i], &buf)) < 0) {
            perror(tab[i]);
            continue;
        } if (!S_ISDIR(buf.st_mode))
            continue;
        if (tab[i][0] == '.')
            continue;
        file = tab[i];
        file = my_strcat(file, "/");
        file = my_strcat(file, tab[i]);
        my_putstr(tab[i]);
        dir = open_my_dir(tab[i]);
        my_recusrive(fill_the_tab(dir), tab[i]);
    }
}