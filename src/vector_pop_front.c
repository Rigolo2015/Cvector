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

int vector_pop_front(Cvector *vector)
{
    int r_value = vector_pop_index(vector, 0);

    return r_value;
}
