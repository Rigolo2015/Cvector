/*
**
** STD::VECTOR IN C
** Rigolo2015, Yannis, 2022
** 
*/

#include <stdio.h>
#include <stdlib.h>

#include "Cvector.h"
#include "value.h"

int vector_clear(Cvector *vector)
{
    if (vector == NULL) {
        printf("[ERR] vector_clear: %s", VECTOR_NULL);
        return ERROR;
    }
    if (vector->size == 0) {
        printf("[ERR] vector_clear: %s", VECTOR_EMPTY);
        return ERROR;
    }
    free(vector->element);
    vector->size = 0;
    return SUCCESS;
}