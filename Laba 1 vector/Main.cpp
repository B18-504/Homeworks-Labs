// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Vector.h"
#include "Interface.h"


int main()
{
    printf("Input type of numbers R or C(a+bi or a-bi): ");
    char number_type;
    scanf_s("%c", &number_type);

    int vector_size1, vector_size2, vector_size3;
    printf("Write vector's sizes by 3 numbers: ");
    scanf_s("%d%d%d", &vector_size1, &vector_size2, &vector_size3); 
    
    printf("Input 1st vector\n");
    vector vectorAI = input_vector(vector_size1, vector_size2, vector_size3, number_type);
    printf("Input 2nd vector\n");
    vector vectorAJ = input_vector(vector_size1, vector_size2, vector_size3, number_type);

    int point;
    while (1)
    {
        menu();
        scanf_s("%d", &point);
        if (point == 3) return 0;
        performer(point, vectorAI, vectorAJ);
    }

    return 0;
}


