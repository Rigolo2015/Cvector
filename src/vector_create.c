/*
**
** STD::VECTOR IN C
** Rigolo2015, Yannis, 2022
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "Cvector.h"
#include "value.h"

Cvector *vector_create(unsigned int nb_value, ...)
{
    va_list values;
    Cvector *vector = malloc(sizeof(Cvector));

    if (vector == NULL) {
        printf("[ERR] vector_create: %s", MALLOC_ERROR);
        return NULL;
    }
    vector->size = nb_value;
    vector->element = malloc(sizeof(type) * nb_value);
    if (vector->element == NULL) {
        printf("[ERR] vector_create: %s", REALLOC_ERROR);
        return NULL;
    }

    va_start(values, nb_value);
    for (unsigned int i = 0; i < nb_value; i++) {
        vector->element[i] = va_arg(values, type);
    }
    va_end(values);
    return vector;
}
