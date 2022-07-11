/*
**
** STD::VECTOR IN C
** Rigolo2015, Yannis, 2022
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "Cvector.h"
#include "value.h"

int vector_push_index(Cvector *vector, type value, unsigned int index)
{
    unsigned int old_vector_index = 0;

    if (vector == NULL) {
        printf("[ERR] vector_push_index: %s", VECTOR_NULL);
        return ERROR;
    }
    if (index > vector->size) {
        printf("[ERR] vector_push_index: %s", INDEX_BIG);
        return ERROR;
    }

    Cvector *new_vector = malloc(sizeof(Cvector));
    if (new_vector == NULL) {
        printf("[ERR] vector_push_index: %s", MALLOC_ERROR);
        return ERROR;
    }
    new_vector->element = malloc(sizeof(type) * (vector->size + 1));
    if (new_vector->element == NULL) {
        printf("[ERR] vector_push_index: %s", MALLOC_ERROR);
        return ERROR;
    }

    for (unsigned int i = 0; i < vector->size + 1; ++i) {
        new_vector->element[i] = vector->element[old_vector_index];
        if (i == index) {
            new_vector->element[i] = value;
            continue;
        }
        old_vector_index += 1;
    }
    vector->element = new_vector->element;
    vector->size += 1;
    return SUCCESS;
}
