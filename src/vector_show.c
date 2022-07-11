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

void vector_show(Cvector *vector, char const *format)
{
    if (vector == NULL) {
        printf("[ERR] vector_show: %s", VECTOR_NULL);
        return;
    }
    if (vector->size == 0) {
        printf("[ERR] vector_show: %s", VECTOR_EMPTY);
        return;
    }
    for (unsigned int i = 0; i < vector->size; i++) {
        printf(format, vector->element[i]);
    }
}
