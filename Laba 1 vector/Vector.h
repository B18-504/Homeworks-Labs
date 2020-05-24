#ifndef VECTOR_H
#define VECTOR_H

struct item
{
    float real = 0;
    float image = 0;
    bool Complex = 0;
};
struct vector
{
    char type;
    int lengthnow;
    void* head;
    int sizetype;
    int reserved;
};


item summ(item a, item b)
{
    item result;
    result.image = a.image + b.image;
    result.real = a.real + b.real;
    if (a.Complex || b.Complex) result.Complex = 1;
    return result;
}
item diff(item a, item b)
{
    item result;
    result.image = a.image - b.image;
    result.real = a.real - b.real;
    if (a.Complex || b.Complex) result.Complex = 1;
    return result;
}
item mult(item a, item b)
{
    item result;
    result.image = a.image * b.real + a.real * b.image;
    result.real = a.real * b.real - a.image * b.image;
    if (a.Complex || b.Complex) result.Complex = 1;
    return result;
}


vector create(char type)
{
    vector result;
    result.type = type;
    result.lengthnow = 0;
    result.reserved = 4;

    if (type == 'v')
    {
        result.sizetype = sizeof(vector);
        result.head = malloc(result.sizetype * result.reserved);
    }
    if (type == 'i')
    {
        result.sizetype = sizeof(item);
        result.head = malloc(result.sizetype * result.reserved);
    }

    return result;
}


void expansion(vector* a)
{
    int add_memory = a->reserved / 2 + a->reserved;
    void* new_memory = malloc(a->sizetype * add_memory);
    void* temp = a->head;

    for (int i = 0; i < a->lengthnow; i++)
    {
        if (a->type == 'i')
        {
            ((item*)new_memory)[i] = ((item*)temp)[i];
        }
        else
        {
            ((vector*)new_memory)[i] = ((vector*)temp)[i];
        }
    }

    a->head = new_memory;
    free(temp);
}


void put(vector* a, void* value)
{
    if (a->lengthnow == a->reserved)
    {
        expansion(a);
    }

    if (a->type == 'i')
    {
        ((item*)a->head)[a->lengthnow] = *((item*)value);
    }
    else
    {
        ((vector*)a->head)[a->lengthnow] = *((vector*)value);
    }
    a->lengthnow++;
}


void* get(vector* a, int i)
{
    if (a->type == 'i') return (void*)(&(((item*)a->head)[i]));
    return (void*)(&(((vector*)a->head)[i]));
}


vector vector_summ(vector a, vector b)
{
    if (a.type == 'v')
    {
        vector result = create('v');
        for (int i = 0; i < a.lengthnow; i++)
        {
            vector first = vector_summ(*((vector*)get(&a, i)), *((vector*)get(&b, i)));
            put(&result, (void*)&first);
        }
        return result;
    }
    else
    {
        vector result = create('i');
        for (int i = 0; i < a.lengthnow; i++)
        {
            item summing = summ(*((item*)get(&a, i)), *((item*)get(&b, i)));
            put(&result, (void*)&summing);
        }
        return result;
    }
}

item vector_scalar_mult(vector a, vector b)
{
    if (a.type == 'v')
    {
        item result;
        for (int i = 0; i < a.lengthnow; i++)
        {
            item inter_result = vector_scalar_mult(*((vector*)get(&a, i)), *((vector*)get(&b, i)));
            result = summ(result, inter_result);
        }
        return result;
    }
    else
    {
        item result;
        for (int i = 0; i < a.lengthnow; i++)
        {
            item multing = mult(*((item*)get(&a, i)), *((item*)get(&b, i)));
            result = summ(result, multing);
        }
        return result;
    }
}

vector vector_mult(vector a, vector b)
{
    if (a.type == 'v')
    {
        vector result = create('v');
        for (int i = 0; i < a.lengthnow; i++)
        {
            vector inter_result = vector_mult(*((vector*)get(&a, i)), *((vector*)get(&b, i)));
            put(&result, (void*)&inter_result);
        }
        return result;
    }
    else
    {
        if (a.lengthnow != 3)
        {
            printf("\n\nIncorrect vectors to calculate vector's mult!");
            return create('i');
        }

        item ax = *((item*)get(&a, 0)), ay = *((item*)get(&a, 1)), az = *((item*)get(&a, 2));
        item bx = *((item*)get(&b, 0)), by = *((item*)get(&b, 1)), bz = *((item*)get(&b, 2));

        vector result = create('i');
        put(&result, &diff(mult(ay, bz), mult(az, by)));   //положил х
        put(&result, &diff(mult(az, bx), mult(ax, bz)));   //положил у
        put(&result, &diff(mult(ax, by), mult(ay, bx)));   //положил z

        return result;
    }
}

#endif
