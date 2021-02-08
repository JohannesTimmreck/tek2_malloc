/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** description
*/

#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
    unsigned char *new_ptr;
    unsigned char *old_ptr;
    malloc_t *meta;

    if (size == 0 && ptr != NULL) {
        free(ptr);
        return (NULL);
    }
    new_ptr = malloc(size);
    if (ptr != NULL) {
        old_ptr = (unsigned char *)ptr;
        meta = ptr - sizeof(malloc_t);
        for (int i = 0; i < meta->in_use && i < size; i++)
            new_ptr[i] = old_ptr[i];
        free(ptr);
    }
    return (new_ptr);
}