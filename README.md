
# Cvector

A lib who create the type Cvector in C.
It's a copy of std::vector in C++.

The goal is to manipulate easily array in C, don't have memory problem, save time, ...

## Usage/Examples

```C
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

//? INFO
//* OUTPUT

int main(void)
{
    //? Create a vector of size 1 with value 1
    Cvector *vector = Cvector_create(1, 1);

    //? Display the vector
    Cvector_show(vector, "- %d\n");
    //* "- 1\n"

    //? Delete the last value 1
    Cvector_pop_back(vector);

    //? Display the vector
    Cvector_show(vector, "- %d\n");
    //* "[ERR] vector_show: vector is empty"

    //? Push 1 at first position of the vector
    Cvector_push_front(vector, (type)1);
    Cvector_show(vector, "- %d\n");
    //* "- 1\n"

    printf("----------------------------\n");

    //? Push 2,3,4,5 at last position of the vector
    Cvector_push_back(vector, (type)2);
    Cvector_push_back(vector, (type)3);
    Cvector_push_back(vector, (type)4);
    Cvector_push_back(vector, (type)5);

    Cvector_show(vector, " %d ->");
    //* " 1 -> 2 -> 3 -> 4 -> 5 ->"

    printf("\n----------------------------\n");

    //? All value of the vector is multiply by 2
    Cvector_for_each(vector, INT, {
        *integer *= 2;
    });

    Cvector_show(vector, " %d ->");
    //* " 2 -> 4 -> 6 -> 8 -> 10 ->"

    printf("\n----------------------------\n");

    //? The vector is reset to NULL
    Cvector_clear(vector);

    Cvector_show(vector, " %d ->");
    //* "[ERR] vector_show: vector is empty"

    printf("----------------------------\n");

    //? Push "hello" and "world" at last position of the vector
    Cvector_push_back(vector, (type)"hello");
    Cvector_push_back(vector, (type)"world");

    Cvector_show(vector, "[%s] -> ");
    //* "[hello] -> [world] ->"

    return SUCCESS;
}
```


## Documentation

You just need to read the include/Cvector.h to discover and understand all functions (;

## Running Tests

To run tests, run the following command

```bash
  make tests_run
```


## Usage

To use him you just need to include the .h file

```c
  #include "Cvector.h"
```
    
## 🚀 About Me
I try to create some cool libs (:
## Authors

- [@YannisDef](https://github.com/YannisDef)

