/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** .
*/

#include "../include/my_ls.h"

char *my_strlowcase(char *str)
{
    char *str2 = malloc(sizeof(char)*1000);

    for (int i = 0;str[i] != '\0';i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str2[i] = str[i] + 32;
        }
        else
            str2[i] = str[i];
    }
    return str2;
}
