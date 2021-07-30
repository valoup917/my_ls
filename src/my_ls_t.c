/*
** EPITECH PROJECT, 2021
** my_ls_t
** File description:
** .
*/

#include "../include/my_ls.h"

void time_switch_t(char **sort_table, int time);

void my_t(char *file)
{
	int time = 0;
    char **tab;
    DIR *dir;

    if (file == NULL)
        file = ".";
    dir = open_my_dir(file);
    tab = fill_the_tab(dir);
    time_switch_t(tab, time);

    closedir(dir);
}

void time_switch_t(char **sort_table, int time)
{
	char *dir1;
	char *dir2;
	struct stat sb;
	char *switch_string = malloc(sizeof(char)*500);

	for (int i = 0;sort_table[i + 1];) {
		dir1 = sort_table[i];
		dir2 = sort_table[i + 1];
		stat(dir1, &sb);
		time = sb.st_mtime;
		stat(dir2, &sb);
		if (time < sb.st_mtime) {
			switch_string = sort_table[i];
			sort_table[i] = sort_table[i+1];
			sort_table[i+1] = switch_string;
			i = 0;
			continue;
		} else
			i++;
	}
    print_my_dir(sort_table);
}