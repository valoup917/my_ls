/*
** EPITECH PROJECT, 2021
** redirection
** File description:
** .
*/

#include "../include/my_ls.h"

void redirection_one(int argc, char *argv[])
{
    if (argc == 2 && argv[1][0] != '-')
        my_ls(argv[1]);
    else if (my_strcmp(argv[1], "-l") == 0 && argc == 2)
        my_l(NULL);
    else if (my_strcmp(argv[1], "-l") == 0 && argc > 2)
        my_l(argv[2]);
    else if (my_strcmp(argv[1], "-t") == 0 && argc == 2)
        my_t(NULL);
    else if (my_strcmp(argv[1], "-t") == 0 && argc > 2)
        my_t(argv[2]);
    else if (my_strcmp(argv[1], "-d") == 0 && argc == 2)
        my_d(NULL);
    else if (my_strcmp(argv[1], "-d") == 0 && argc > 2)
        my_d(argv[2]);
    else if (my_strcmp(argv[1], "-r") == 0 && argc == 2)
        my_r(NULL);
    else if (my_strcmp(argv[1], "-r") == 0 && argc > 2)
        my_r(argv[2]);
    else if (my_strcmp(argv[1], "-R") == 0)
        my_big_r();
}