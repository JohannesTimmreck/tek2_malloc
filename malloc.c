/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** description
*/

#include "malloc.h"

malloc_t *heap = NULL;

void init_struct(void *address, size_t used_size, malloc_t *last)
{
    malloc_t *new_mem = address;

    if (address == NULL)
        return;
    new_mem->in_use = used_size;
    if (last != NULL) {
        new_mem->next = last->next;
        last->next = new_mem;
    } else
        new_mem->next = NULL;
    new_mem->previous = last;
    new_mem->addr = address + sizeof(malloc_t);
    new_mem->end = address + sizeof(malloc_t) + used_size;
}

void *allocate_new_mem(size_t size)
{
    void *addr;
    malloc_t *new_mem;
    int page_size = getpagesize();
    size_t to_allocate = page_size * 2;
    int test = 0;

    while (size > to_allocate)
        to_allocate += page_size * 2;
    addr = sbrk(to_allocate);
    test = *(int *)addr;
    if (test == -1)
        return (NULL);
    new_mem = addr;
    new_mem->size = to_allocate - sizeof(malloc_t);
    return (addr);
}

malloc_t *find_space(size_t size, size_t mem)
{
    malloc_t *new_mem;
    malloc_t *tmp = heap;

    do {
        if (tmp->size - tmp->in_use >= mem ) {
            new_mem = tmp->addr + tmp->in_use;
            new_mem->size = tmp->size - tmp->in_use;
            tmp->size = tmp->in_use;
            init_struct(new_mem, size, tmp);
            return (new_mem);
        }
        if (tmp->next != NULL)
            tmp = tmp->next;
        else
            break;
    } while (1);
    new_mem = allocate_new_mem(mem);
    init_struct(new_mem, size, tmp);
    return (new_mem);
}

void *find_mem_address(size_t size, size_t mem)
{
    malloc_t *new_mem;

    if (heap == NULL) {
        new_mem = allocate_new_mem(mem);
        init_struct(new_mem, size, NULL);
        heap = new_mem;
    } else {
        new_mem = find_space(size, mem);
    }
    return (new_mem);
}

void *malloc(size_t size)
{
    void *address;
    size_t min_required = size;
    size_t size_to_allocate = 1;

    while (size_to_allocate < min_required)
        size_to_allocate *= 2;
    size_to_allocate += sizeof(malloc_t);
    address = find_mem_address(size, size_to_allocate);
    if (address == NULL)
        return (NULL);
    return (address + sizeof(malloc_t));
}
