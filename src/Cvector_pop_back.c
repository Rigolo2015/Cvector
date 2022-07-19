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

int Cvector_pop_back(Cvector *vector)
{
    int r_value = Cvector_pop_index(vector, vector->size);

    return r_value;
}
