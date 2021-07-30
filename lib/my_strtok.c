/*
** EPITECH PROJECT, 2021
** my_strtok
** File description:
** .
*/

#include "../include/my_ls.h"

int verification(char *str, char a);

char *my_strtok(char *str, char c)
{
    int i = 0;
    int n = 0;
    char *new = malloc(sizeof(char)* my_strlen(str));

    if (verification(str, c) == 1) {
        for (;str[i] != c && str[i] != '\0';i++);
        i++;
        for (;str[i] != '\0';i++) {
            new[n] = str[i];
            n++;
        }
        new[n] = '\0';
        return new;
    }
    else
        return str;
}

int verification(char *str, char a)
{
    for (int i = 0;str[i] != '\0';i++) {
        if (str[i] == a)
            return 1;
    }
    return 0;
}