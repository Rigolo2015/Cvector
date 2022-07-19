/*
**
** STD::VECTOR IN C
** Rigolo2015, Yannis, 2022
** 
*/

#include <criterion/criterion.h>
#include <stdio.h>

#include "Cvector.h"
#include "value.h"

Test(vector_create, create_function_with_number)
{
    Cvector *vector = Cvector_create(2, (type)21, (type)42);

    cr_assert_eq(vector->element[0], 21, "Test 01");
    cr_assert_eq(vector->element[1], 42, "Test 02");
    cr_assert_eq(vector->size, 2, "Test 03");
}

Test(vector_create, create_function_with_strs)
{
    Cvector *vector = Cvector_create(1, (type)"hello");

    cr_assert_eq(vector->element[0], "hello", "Test 01");
    cr_assert_eq(vector->size, 1, "Test 02");
}

Test(vector_create, create_function_with_one_str)
{
    Cvector *vector = Cvector_create(0);

    cr_assert_eq(vector->size, 0, "Test 01");
}

/*-----------------------------------------------------------------*/

Test(vector_clear, clean_function_empty)
{
    Cvector *vector = NULL;

    cr_assert_eq(Cvector_clear(vector), ERROR, "Test 01");
}

Test(vector_clear, clean_function)
{
    Cvector *vector = Cvector_create(2, (type)"hello", (type)"world");

    Cvector_clear(vector);
    cr_assert_eq(vector->size, 0, "Test 01");
}

/*-----------------------------------------------------------------*/

Test(vector_push_back, push_back_function_with_nbr)
{
    Cvector *vector = Cvector_create(2, (type)21, (type)42);

    cr_assert_eq(vector->element[0], 21, "Test 01");
    cr_assert_eq(vector->element[1], 42, "Test 02");
    cr_assert_eq(vector->size, 2, "Test 03");

    Cvector_push_back(vector, (type)84);
    cr_assert_eq(vector->element[0], 21, "Test 04");
    cr_assert_eq(vector->element[1], 42, "Test 05");
    cr_assert_eq(vector->element[2], 84, "Test 06");
    cr_assert_eq(vector->size, 3, "Test 07");
}

/*-----------------------------------------------------------------*/

Test(vector_push_index, push_index_function_with_nbr)
{
    Cvector *vector = Cvector_create(2, (type)21, (type)42);

    cr_assert_eq(vector->element[0], 21, "Test 01");
    cr_assert_eq(vector->element[1], 42, "Test 02");
    cr_assert_eq(vector->size, 2, "Test 03");

    Cvector_push_index(vector, (type)84, 1);
    cr_assert_eq(vector->element[0], 21, "Test 04");
    cr_assert_eq(vector->element[1], 84, "Test 05");
    cr_assert_eq(vector->element[2], 42, "Test 06");
    cr_assert_eq(vector->size, 3, "Test 07");

    Cvector_push_index(vector, (type)-5, 0);
    cr_assert_eq(vector->element[0], -5, "Test 08");
    cr_assert_eq(vector->element[1], 21, "Test 09");
    cr_assert_eq(vector->element[2], 84, "Test 10");
    cr_assert_eq(vector->element[3], 42, "Test 11");
    cr_assert_eq(vector->size, 4, "Test 12");

}

/*-----------------------------------------------------------------*/

Test(vector_push_front, push_front_function_with_nbr)
{
    Cvector *vector = Cvector_create(2, (type)21, (type)42);

    Cvector_push_front(vector, (type)84);
    cr_assert_eq(vector->element[0], 84, "Test 01");
    cr_assert_eq(vector->element[1], 21, "Test 02");
    cr_assert_eq(vector->element[2], 42, "Test 03");
    cr_assert_eq(vector->size, 3, "Test 04");

    Cvector_push_front(vector, (type)-5);
    cr_assert_eq(vector->element[0], -5, "Test 05");
    cr_assert_eq(vector->element[1], 84, "Test 06");
    cr_assert_eq(vector->element[2], 21, "Test 07");
    cr_assert_eq(vector->element[3], 42, "Test 08");
    cr_assert_eq(vector->size, 4, "Test 09");
}

/*-----------------------------------------------------------------*/

Test(vector_pop_index, pop_index_function_with_nbr)
{
    Cvector *vector = Cvector_create(3, (type)21, (type)42, (type)84);

    Cvector_pop_index(vector, 0);

    cr_assert_eq(vector->element[0], 42, "Test 01");
    cr_assert_eq(vector->element[1], 84, "Test 02");
    cr_assert_eq(vector->size, 2, "Test 03");

    Cvector_push_front(vector, (type)-5);
    Cvector_push_back(vector, (type)50);
    cr_assert_eq(vector->element[0], -5, "Test 04");
    cr_assert_eq(vector->element[1], 42, "Test 05");
    cr_assert_eq(vector->element[2], 84, "Test 06");
    cr_assert_eq(vector->element[3], 50, "Test 07");
    cr_assert_eq(vector->size, 4, "Test 08");

    Cvector_pop_index(vector, 2);
    cr_assert_eq(vector->element[0], -5, "Test 09");
    cr_assert_eq(vector->element[1], 42, "Test 10");
    cr_assert_eq(vector->element[2], 50, "Test 11");
    cr_assert_eq(vector->size, 3, "Test 12");

    Cvector_pop_index(vector, 1);
    cr_assert_eq(vector->element[0], -5, "Test 13");
    cr_assert_eq(vector->element[1], 50, "Test 14");
    cr_assert_eq(vector->size, 2, "Test 15");

    int r_value = Cvector_pop_index(vector, 42);
    cr_assert_eq(vector->element[0], -5, "Test 16");
    cr_assert_eq(vector->element[1], 50, "Test 17");
    cr_assert_eq(r_value, ERROR, "Test 18");
}

/*-----------------------------------------------------------------*/

Test(vector_pop_front, pop_front_function_with_nbr)
{
    Cvector *vector = Cvector_create(3, (type)21, (type)42, (type)84);

    Cvector_pop_front(vector);

    cr_assert_eq(vector->element[0], 42, "Test 01");
    cr_assert_eq(vector->element[1], 84, "Test 02");
    cr_assert_eq(vector->size, 2, "Test 03");

    Cvector_push_front(vector, (type)-5);
    Cvector_push_back(vector, (type)50);
    cr_assert_eq(vector->element[0], -5, "Test 04");
    cr_assert_eq(vector->element[1], 42, "Test 05");
    cr_assert_eq(vector->element[2], 84, "Test 06");
    cr_assert_eq(vector->element[3], 50, "Test 07");
    cr_assert_eq(vector->size, 4, "Test 08");

    Cvector_pop_front(vector);
    cr_assert_eq(vector->element[0], 42, "Test 09");
    cr_assert_eq(vector->element[1], 84, "Test 10");
    cr_assert_eq(vector->element[2], 50, "Test 11");
    cr_assert_eq(vector->size, 3, "Test 12");

    Cvector_pop_front(vector);
    Cvector_pop_front(vector);
    Cvector_pop_front(vector);

    int r_value = Cvector_pop_front(vector);
    cr_assert_eq(r_value, ERROR, "Test 13");
}

/*-----------------------------------------------------------------*/

Test(vector_pop_back, pop_back_function_with_nbr)
{
    Cvector *vector = Cvector_create(3, (type)21, (type)42, (type)84);

    Cvector_pop_back(vector);
    cr_assert_eq(vector->element[0], 21, "Test 01");
    cr_assert_eq(vector->element[1], 42, "Test 02");
    cr_assert_eq(vector->size, 2);

    Cvector_push_front(vector, (type)-5);
    Cvector_push_back(vector, (type)50);
    cr_assert_eq(vector->element[0], -5, "Test 03");
    cr_assert_eq(vector->element[1], 21, "Test 04");
    cr_assert_eq(vector->element[2], 42, "Test 05");
    cr_assert_eq(vector->element[3], 50, "Test 06");
    cr_assert_eq(vector->size, 4, "Test 07");

    Cvector_pop_back(vector);
    cr_assert_eq(vector->element[0], -5, "Test 08");
    cr_assert_eq(vector->element[1], 21, "Test 09");
    cr_assert_eq(vector->element[2], 42, "Test 10");
    cr_assert_eq(vector->size, 3, "Test 11");

    Cvector_pop_back(vector);
    Cvector_pop_back(vector);
    Cvector_pop_back(vector);

    int r_value = Cvector_pop_back(vector);
    cr_assert_eq(r_value, ERROR, "Test 12");
}

/*-----------------------------------------------------------------*/

Test(vector_for_each, use_for_each_with_nbr)
{
    Cvector *vector = Cvector_create(4, 1, 2, 3, 4);

    Cvector_for_each(vector, INT, {
        *integer = *integer + 2 * 9;
    });

    cr_assert_eq(vector->element[0], 19, "Test 01");
    cr_assert_eq(vector->element[1], 20, "Test 02");
    cr_assert_eq(vector->element[2], 21, "Test 03");
    cr_assert_eq(vector->element[3], 22, "Test 04");

    Cvector_for_each(vector, INT, {
        *integer = *integer + 2 * 9;
    });

    cr_assert_eq(vector->element[0], 37, "Test 05");
    cr_assert_eq(vector->element[1], 38, "Test 06");
    cr_assert_eq(vector->element[2], 39, "Test 07");
    cr_assert_eq(vector->element[3], 40, "Test 08");
}

Test(vector_for_each, use_for_each_with_string)
{
    Cvector *vector_str = Cvector_create(4, strdup("a"), strdup("b"), strdup("c"), strdup("d"));

    Cvector_for_each(vector_str, CHAR, {
        strcat(string, " Hello");
    });

    cr_assert_str_eq(vector_str->element[0], "a Hello", "Test 01");
    cr_assert_str_eq(vector_str->element[1], "b Hello", "Test 02");
    cr_assert_str_eq(vector_str->element[2], "c Hello", "Test 03");
    cr_assert_str_eq(vector_str->element[3], "d Hello", "Test 04");

    Cvector_for_each(vector_str, CHAR, {
        strcat(string, " No");
    });

    cr_assert_str_eq(vector_str->element[0], "a Hello No", "Test 05");
    cr_assert_str_eq(vector_str->element[1], "b Hello No", "Test 06");
    cr_assert_str_eq(vector_str->element[2], "c Hello No", "Test 07");
    cr_assert_str_eq(vector_str->element[3], "d Hello No", "Test 08");
}