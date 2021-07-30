/*
** EPITECH PROJECT, 2020
** step 1
** File description:
** .
*/

#include "../include/my_ls.h"

int main(int argc, char *argv[])
{
    errors(argc, argv);
    if (argc == 1)
        my_ls(NULL);
    else
        redirection_one(argc, argv);
    return 0;
}

char **fill_the_tab(DIR *dir)
{
    struct dirent *sd;
    int i = 0;
    char **tab = malloc(sizeof(char *)*1000);

    for (i = 0; (sd = readdir(dir)) != NULL; i++) {
        tab[i] = malloc(sizeof(char)*my_strlen(sd->d_name));
        tab[i] = sd->d_name;
    }
    tab[i + 1] = NULL;
    tab = sorting(tab);
    return tab;
}

DIR *open_my_dir(char *file)
{
    DIR *dir;

    dir = opendir(file);
    if (dir == NULL)
        exit(84);

    return dir;
}

int errors(int argc, char *argv[])
{
    DIR *dir;

    for (int i = 1;i != argc;i++) {
        dir = opendir(argv[i]);
        if (argv[i][0] != '-' && dir == NULL)
            exit(84);
    }
    return 0;
}

char **sorting(char **sort_table)
{
    char *switch_string = malloc(sizeof(char)*500);
    char *a = malloc(sizeof(char)*200);
    char *b = malloc(sizeof(char)*200);

    for (int i = 0;sort_table[i] != NULL;i++) {
        for (int y = 0;sort_table[y] != NULL;y++) {
            a = my_strlowcase(sort_table[i]);
            b = my_strlowcase(sort_table[y]);
            if (my_strcmp(a, b) < 0) {
                switch_string = sort_table[i];
                sort_table[i] = sort_table[y];
                sort_table[y] = switch_string;
            }
        }
    }
    free(a);
    free(b);
    return sort_table;
}


int main()
{
    int n;
    scanf("%d", &n);
    char **word = malloc(sizeof(char *) * 500);
    for (int i = 0; i < n; i++) {
        word[i] = malloc(sizeof(char) * 501);
        scanf("%s", word[i]);
    }
    word = sort(word);
    for (int i = 0; word[i]; i++) {
        printf("%s\n", word[i]);
    }
    return 0;
}

char **sort(char **sort_table)
{
    char *switch_string = malloc(sizeof(char)*500);
    char *a = malloc(sizeof(char)*200);
    char *b = malloc(sizeof(char)*200);

    for (int i = 0;sort_table[i];i++) {
        for (int y = 0;sort_table[y];y++) {
            a = sort_table[i];
            b = sort_table[y];
            if (strlen(a) < strlen(b)) {
                switch_string = sort_table[i];
                sort_table[i] = sort_table[y];
                sort_table[y] = switch_string;
            }
        }
    }
    return sort_table;
}


n = int(input())
word = []
for i in range(n):
    word.append(input())
print(*sorted(word, key=len), sep='\n')