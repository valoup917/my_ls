/*
** EPITECH PROJECT, 2021
** ls -l 2
** File description:
** .
*/

#include "../include/my_ls.h"

void owner_name(char *str)
{
    struct stat buf;
    struct passwd *user;
    struct group *group;

    stat(str, &buf);
    user = getpwuid(buf.st_uid);
    group = getgrgid(buf.st_gid);

    my_putstr(user->pw_name);
    my_putstr(" ");
    my_putstr(group->gr_name);
    my_putstr(" ");
}

void nb_links(char *str)
{
    struct stat buf;

    stat(str, &buf);
    my_put_nbr(buf.st_nlink);
    my_putstr(" ");
}

void total_l(char **tab)
{
    int result = 0;
    struct stat buf;

    for (int i = 0;tab[i];i++) {
        stat(tab[i], &buf);
        if (tab[i][0] != '.')
            result += buf.st_blocks;
    }
    result = (result / 2);
    my_putstr("total ");
    my_put_nbr(result);
    my_putchar('\n');
}

void type_bis(char *a)
{
    struct stat buf;

    stat(a, &buf);
    if (S_ISREG(buf.st_mode))
        my_putstr("-");
    if (S_ISDIR(buf.st_mode))
        my_putstr("d");
    if (S_ISCHR(buf.st_mode))
        my_putstr("c");
    if (S_ISBLK(buf.st_mode))
        my_putstr("b");
    if (S_ISFIFO(buf.st_mode))
        my_putstr("p");
    if (S_ISLNK(buf.st_mode))
        my_putstr("l");
    if (S_ISSOCK(buf.st_mode))
        my_putstr("s");
}

void permission(char *a)
{
    struct stat buf;

    stat(a, &buf);
    my_putstr((buf.st_mode & S_IRUSR) ? "r" : "-");
    my_putstr((buf.st_mode & S_IWUSR) ? "w" : "-");
    my_putstr((buf.st_mode & S_IXUSR) ? "x" : "-");
    my_putstr((buf.st_mode & S_IRGRP) ? "r" : "-");
    my_putstr((buf.st_mode & S_IWGRP) ? "w" : "-");
    my_putstr((buf.st_mode & S_IXGRP) ? "x" : "-");
    my_putstr((buf.st_mode & S_IROTH) ? "r" : "-");
    my_putstr((buf.st_mode & S_IWOTH) ? "w" : "-");
    my_putstr((buf.st_mode & S_IXOTH) ? "x" : "-");
    my_putstr(".");
}