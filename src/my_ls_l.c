/*
** EPITECH PROJECT, 2021
** ls _ l
** File description:
** .
*/

#include "../include/my_ls.h"

void my_l(char *file)
{
    char **tab;
    DIR *dir;
    int cdt = 0;

    if (file == NULL) {
        cdt = 1;
        file = ".";
    }
    dir = open_my_dir(file);
    tab = fill_the_tab(dir);
    if (cdt == 0)
        tab = modif_the_tab(tab, file);
    direction(tab);
    closedir(dir);
}

char **modif_the_tab(char **tab, char *file)
{
    int i = 0;
    while (tab[i]) {
        if (tab[i][0] != '.')
            tab[i] = my_strcat(file, tab[i]);
        i++;
    }
    return tab;
}

void direction(char **tab)
{
    total_l(tab);
    for (int i = 0;tab[i];i++) {
        if (tab[i][0] != '.') {
            type_bis(tab[i]);
            permission(tab[i]);
            my_putstr(" ");
            nb_links(tab[i]);
            owner_name(tab[i]);
            file_size(tab[i]);
            date_print(tab[i]);
            my_putstr(" ");
            my_putstr(my_strtok(tab[i], '/'));
            my_putstr("\n");
        }
    }
}

void date_print(char *str)
{
    struct stat buf;
    char *time_mod;
    char *time;
    int y = 0;
    int i = 4;

    stat(str, &buf);
    time = ctime(&buf.st_mtime);
    time_mod = malloc(sizeof(char)*13);

    for (;i != 16;i++) {
        time_mod[y] = time[i];
        y++;
    }
    time_mod[12] = '\0';
    my_putstr(time_mod);
}

void file_size(char *str)
{
    struct stat buf;

    stat(str, &buf);
    my_put_nbr(buf.st_size);
    my_putstr("  ");
}