/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** description
*/

#include "malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    unsigned char *new_mem;
    unsigned char *old_mem = (unsigned char *)ptr;
    malloc_t *meta;

    if (nmemb == 0 || size == 0 || ptr == NULL)
        return (NULL);
    new_mem = malloc(nmemb * size);
    if (ptr != NULL) {
        meta = ptr - sizeof(malloc_t);
        for (int i = 0; i < meta->in_use && i < size; i++)
            new_mem[i] = old_mem[i];
        free(ptr);
    }
    return (new_mem);
}

