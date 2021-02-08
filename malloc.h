/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** description
*/

#ifndef PSU_2019_MALLOC_MALLOC_H
#define PSU_2019_MALLOC_MALLOC_H

#include <stdbool.h>
#include <unistd.h>

typedef struct malloc_s malloc_t;
struct malloc_s {
    size_t size;
    size_t in_use;
    void *addr;
    void *end;
    malloc_t *previous;
    malloc_t *next;
};

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif //PSU_2019_MALLOC_MALLOC_H
