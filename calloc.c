/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** description
*/

#include "malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    unsigned char *mem;

    if (nmemb == 0 || size == 0)
        return (NULL);
    mem = malloc(nmemb * size);
    for (int i = 0; i < nmemb; ++i)
        mem[i] = 0;
    return (mem);
}