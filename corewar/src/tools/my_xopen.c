/*
** EPITECH PROJECT, 2020
** my_xopen
** File description:
** my_xopen
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

int my_xopen(char *path)
{
    int fd;

    if ((fd = open(path, O_RDONLY)) < 0) {
        write(2, "File not accessible\n", 20);
        exit(1);
    }
    return (fd);
}