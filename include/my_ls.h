/*
** EPITECH PROJECT, 2020
** include
** File description:
** .
*/

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strcmp(char *str_o, char *str_c);
char *my_strlowcase(char *str);
char **my_revstr(char **sort_table);
int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
char *my_strtok(char *str, char c);

int errors(int argc, char *argv[]);
char **sorting(char **sort_table);
char **fill_the_tab(DIR *dir);

void permission(char *a);
void type_bis(char *a);
void date_print(char *time);

/*REMASTER*/
DIR *open_my_dir(char *file);
void print_my_dir(char **string);
void my_l(char *file);
void my_ls(char *file);
void my_t(char *file);
void my_d(char *file);
void my_r(char *file);
void my_big_r(void);
void total_l(char **tab);
void direction(char **tab);
char **fill_the_tab(DIR *dir);

void nb_links(char *str);
void owner_name(char *str);
void file_size(char *str);
char **modif_the_tab(char **tab, char *file);
void redirection_one(int argc, char *argv[]);