/*
**
** STD::VECTOR IN C
** Rigolo2015, Yannis, 2022
** 
*/

#ifndef Cvector_H_
    #define Cvector_H_

//TODO rendre les erreurs (-1) plus précises avec des defines

#define VECTOR_NULL "vector is NULL\n"
#define VECTOR_EMPTY "vector is empty\n"

#define INDEX_BIG "index is too big\n"

#define MALLOC_ERROR "malloc error\n"
#define REALLOC_ERROR "realloc error\n"

#define INT 0
#define CHAR 1

typedef void * type;
typedef struct Cvector {
    type *element;
    unsigned int size;
} Cvector;

/**
 * @brief Go through all the elements one by one by renaming them (integer: int, string: char *)
 * 
 * @param vector vector you want use
 * @param type type of the element in vector (int, char *)
 * @param commands commands you want to do with the vector inside the loop
 */
#define for_each(vector, type, commands)                    \
    for (unsigned int i = 0; i < vector->size; ++i) {       \
        int *integer;                                           \
        char *string;                                           \
        if (type == INT) {                                  \
            integer = (int *)&(vector->element[i]);         \
        }                                                   \
        if (type == CHAR) {                                 \
            string = (char *)vector->element[i];            \
        }                                                   \
        commands                                            \
    }

/**
 * @brief Create a vector with nb args you want
 * 
 * @param nb_value number of value you need to put in vector
 * @param ... values you want to put in vector (int, char *, struct, ...)
 * @return Cvector *
 */
Cvector *vector_create(unsigned int nb_value, ...);

/**
 * @brief free Cvector->element
 * 
 * @return int 0 if success, else -1
 */
int vector_clear(Cvector *);  // remove all the elements of the vector container

/**
 * @brief Push the elements into a vector from the back
 * 
 * @param vector 
 * @param value what you need to push
 * @return int 0 if success, else -1
 */
int vector_push_back(Cvector *vector, type value);

/**
 * @brief  Push elements from a vector from the front
 * 
 * @param vector 
 * @param value what you need to push
 * @return int 0 if success, else -1
 */
int vector_push_front(Cvector *vector, type value);

/**
 * @brief Extends the container by inserting new element at position
 * 
 * @param vector 
 * @param value what you need to push
 * @param index 
 * @return int 0 if success, else -1
 */
int vector_push_index(Cvector *vector, type value, unsigned int index);

/**
 * @brief Pop/remove elements from a vector from the back
 * 
 * @param vector 
 * @return int 0 if success, else -1
 */
int vector_pop_back(Cvector *vector);

/**
 * @brief Pop or remove elements from a vector from the front
 * 
 * @param vector 
 * @return int 0 if success, else -1
 */
int vector_pop_front(Cvector *vector);

/**
 * @brief Pop or remove elements from a vector from the index
 * 
 * @param vector 
 * @param index position of element you want to remove
 * @return int 0 if success, else -1
 */
int vector_pop_index(Cvector *vector, unsigned int index);

/**
 * @brief Show the vector
 * 
 * @param vector vector you want to show
 * @param format string you will put in printf
 */
void vector_show(Cvector *vector, char const *format);

#endif
