/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** description
*/

#include "malloc.h"

extern malloc_t *heap;

void free_last(malloc_t *to_be_freed)
{
    size_t page = 2 * getpagesize();
    size_t to_deallocate = 0;

    to_be_freed += sizeof(malloc_t);
    while (to_be_freed->size >= page) {
        to_be_freed->size -= page;
        to_deallocate += page;
    }
    sbrk(-to_deallocate);
    if (to_be_freed->previous != NULL) {
        to_be_freed->previous->size += to_be_freed->size;
        to_be_freed->previous->next = NULL;
    }
    to_be_freed = NULL;
}

void free_middle(malloc_t *to_be_freed)
{
    to_be_freed->previous->size += to_be_freed->size + sizeof(malloc_t);
    to_be_freed->previous->next = to_be_freed->next;
    to_be_freed->next->previous = to_be_freed->previous;
    to_be_freed = NULL;
}

void manage_free(malloc_t *to_be_freed)
{
    if (to_be_freed->next == NULL) {
        free_last(to_be_freed);
    } else if (to_be_freed->previous != NULL) {
        free_middle(to_be_freed);
    } else {
        to_be_freed->in_use = 0;
    }
}

void free(void *ptr)
{
    malloc_t *tmp = heap;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->addr == ptr) {
            manage_free(tmp);
            break;
        }
    }
    if (heap != NULL && heap->in_use == 0)
        manage_free(heap);
}
