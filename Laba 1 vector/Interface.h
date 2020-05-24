#ifndef INTERFACE_H
#define INTERFACE_H
#include "Vector.h"
#include <stdio.h>

void print_item(item input_number)
{
    if (input_number.Complex)
    {
        if (input_number.image >= 0)
        {
            printf("%f+%fi ", input_number.real, input_number.image);
        }
        else
        {
            printf("%f%fi ", input_number.real, input_number.image);
        }
    }
    else
    {
        printf("%f ", input_number.real);
    }
}

int def_input_number(char type, item* input_number)
{
    if (type == 'R')
    {
        float read_number;
        scanf_s("%f", &read_number);
        input_number->real = read_number;
        input_number->image = 0;
        input_number->Complex = 0;
        return 1;
    }
    else if (type == 'C')
    {
        float read_real_number, read_image_number;
        scanf_s("%f%fi", &read_real_number, &read_image_number);// 2+3i
        input_number->real = read_real_number;
        input_number->image = read_image_number;
        input_number->Complex = 1;
        return 1;
    }
    return 0;// возвратит 0, если пришел непонятный тип ввода
}

vector input_vector(int vector_size1, int vector_size2, int vector_size3, char input_type)
{
    vector vector_input = create('v');
    for (int i = 0; i < vector_size1; i++)
    {
        vector vector_item1 = create('v');
        for (int j = 0; j < vector_size2; j++)
        {
            vector vector_item2 = create('i');
            for (int k = 0; k < vector_size3; k++)
            {
                item tmp;
                def_input_number(input_type, &tmp);
                put(&vector_item2, &tmp);
            }
            put(&vector_item1, &vector_item2);
        }
        put(&vector_input, &vector_item1);
    }
    return vector_input;
}

void print_vector(vector inputvector)
{
    printf("\n\n");
    for (int i = 0; i < inputvector.lengthnow; i++)
    {
        int inputvector2length = ((vector*)get(&inputvector, i))->lengthnow;
        for (int j = 0; j < inputvector2length; j++)
        {
            int inputvector3length = ((vector*)get((vector*)get(&inputvector, i), j))->lengthnow;
            for (int k = 0; k < inputvector3length; k++)
            {
                print_item(*((item*)get((vector*)get((vector*)get(&inputvector, i), j), k)));
            }
            printf("\n");
        }
        printf("\n");
    }
}

void menu()
{
    printf("Input 0 to calculate vector's summ\n");
    printf("Input 1 to caltulate vector's scalar multing\n");
    printf("Input 2 to calculate vector's vector multing\n");
    printf("Input 3 to exit\n");
    printf("Input chosen point: ");
}

void performer(int problem_cod, vector a, vector b)
{
    switch (problem_cod)
    {
    case 0:
        print_vector((vector_summ(a, b)));
        break;
    case 1:
        print_item((vector_scalar_mult(a, b)));
        printf("\n");
        break;
    case 2:
        print_vector((vector_mult(a, b)));
        break;
    default:
        break;
    }
}

#endif