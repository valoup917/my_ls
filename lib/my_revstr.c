/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** .
*/

#include "../include/my_ls.h"

char **my_revstr(char **sort_table)
{
    int n = 0;
    int d = 0;
    int len;
    char *b;
    int z = 0;

    for (int i = 1;sort_table[i] != NULL;i++) {
        sort_table[z] = sort_table[i];
        z++;
    }
    for (;sort_table[n] != NULL;n++);
    len = n - 1;
    for (int i = 0; i <= len / 2;i++) {
        b = sort_table[n-1];
        sort_table[n-1] = sort_table[d];
        sort_table[d] = b;
        d++;
        n--;
    }
    return (sort_table);
}
