#ifndef dyn_h
#define dyn_h
#include "strings.h"
#include <stdbool.h>

/*
void waitFor (unsigned int secs) {
    unsigned int retTime = (unsigned)(time(0) + secs);
    while (time(0) < retTime);
}
*/

void** string_massive_set_keyboard(void** mass, int N) {
    int i;
    
    if (mass == NULL) {
        mass = malloc(sizeof(void*) * N);
    }
    else {
        mass = realloc(mass, sizeof(void*) * N);
    }
    for (i = 0; i < N; i += 1) {
        *(mass + i) = malloc(sizeof(struct string*));
        printf("Data: ");
        string_set((struct string*)*(mass+i));
    }
    
    return mass;
}

void** string_massive_set_auto(void** mass, int N) {
    int i;
    long int t = time(NULL);
    
    if (mass == NULL) {
        mass = malloc(sizeof(void*) * N);
    }
    else {
        mass = realloc(mass, sizeof(void*) * N);
    }
    
    for (i = 0; i < N; i += 1) {
        *(mass + i) = malloc(sizeof(struct string*));
        string_set_random((struct string*)*(mass + i), t+i*97);
    }
    
    return mass;
}

void string_massive_print(void** mass, int N) {
    int i;
    for (i = 0; i < N; i += 1) {
        string_print(*(mass + i));
        printf(" ");
    }
}

void** int_massive_set_keyboard(void** mass, int N) {
    int i;
    
    if (mass == NULL) {
        mass = malloc(sizeof(void*) * N);
    }
    else {
        mass = realloc(mass, sizeof(void*) * N);
    }
    for (i = 0; i < N; i += 1) {
        *(mass + i) = malloc(sizeof(int*));
        printf("Data: ");
        scanf("%d", (int*)*(mass + i));
    }
    
    return mass;
}

void** int_massive_set_auto(void** mass, int N) {
    int i;
    srand((unsigned)time(NULL));
    
    if (mass == NULL) {
        mass = malloc(sizeof(void*) * N);
    }
    else {
        mass = realloc(mass, sizeof(void*) * N);
    }
    
    for (i = 0; i < N; i += 1) {
        *(mass + i) = malloc(sizeof(int*));
        *(int*)*(mass + i) = (rand() % (100 - (-100))) + (-100);
        while ((*(int*)*(mass + i) > 100) || (*(int*)*(mass + i) < -100)) {
            *(int*)*(mass + i) = (rand() % (100 - (-100))) + (-100);
        }
    }
    
    return mass;
}

void int_massive_print(void** mass, int N) {
    int i;
    
    for (i = 0; i < N; i += 1) {
        printf("%d", *(int*)*(mass + i));
        printf(" ");
    }
}

void** massive_concat(void** mass1, int N1, void** mass2, int N2) {
    void **concat = malloc(sizeof(void*) * (N1 + N2));
    
    if ((N1 == 0) || (N2 == 0)) {
        printf("\n***ERROR***\n");
        exit(1);
    }
    int i = 0, j = 0;
    
    while (i < N1) {
        concat[i] = mass1[i];
        i += 1;
    }
    while (j < N2) {
        concat[i] = mass2[j];
        i += 1;
        j += 1;
    }
    
    return concat;
}

void massive_sort(void** mass, int N, void(*f)(void**, int, int)) {
    f(mass, 0, N-1);
}

/* SPECIAL FUNCTIONS TO CALL WITH MASSIVE_SORT */

void int_massive_quicksort(void** mass, int f, int N) {
    if (f < N) {
        int left = f, right = N;
        void *middle = *(mass + ((left + right)/2)), *mem;
        
        while (left <= right) {
            while (*(int*)*(mass + left) < *(int*)middle) {
                left += 1;
            }
            while (*(int*)*(mass + right) > *(int*)middle) {
                right -= 1;
            }
            if (left <= right) {
                mem = *(mass + left);
                *(mass + left) = *(mass + right);
                *(mass + right) = mem;
                left += 1;
                right -= 1;
            }
        }
        int_massive_quicksort(mass, f, right);
        int_massive_quicksort(mass, left, N);
    }
}

void string_massive_quicksort(void** mass, int f, int N) {
    if (f < N) {
        int left = f, right = N;
        void *middle = *(mass + ((left + right)/2)), *mem;
        
        while (left <= right) {
            while (string_compare((struct string*)*(mass + left), (struct string*)middle) < 0) {
                left += 1;
            }
            while ((string_compare((struct string*)*(mass + right), (struct string*)middle) > 0)) {
                right -= 1;
            }
            if (left <= right) {
                mem = *(mass + left);
                *(mass + left) = *(mass + right);
                *(mass + right) = mem;
                left += 1;
                right -= 1;
            }
        }
        string_massive_quicksort(mass, f, right);
        string_massive_quicksort(mass, left, N);
    }
}

//////////////////////////////////////////////

void map(void** mass, int N, void(*f)(void*)) {
    int i;
    
    for (i = 0; i < N; i += 1) {
        f(*(mass + i));
    }
}

void** where(void** mass, int* N, bool(*f)(void*)) {
    int i, j = 0;
    void **arr = malloc(sizeof(void*) * (*N));
    
    for (i = 0; i < *N; i += 1) {
        if (f(*(mass + i)) == true) {
            *(arr + j) = *(mass + i);
            j += 1;
        }
    }
    *N = j;
    
    return arr;
}

/*  SPECIAL FUNCTIONS TO CALL WITH MAP */

void int_plus_one(void* element) {
    *(int*)element += 1;
}

void int_minus_ten(void* element) {
    *(int*)element -= 10;
}

void string_plus_1(void* element) {
    struct string a;
    a.str[0] = '1';
    a.str[1] = '\0';
    *(struct string*)element = string_concat((struct string*)element, &a);
}

void string_double(void* element) {
    *(struct string*)element = string_concat((struct string*)element, (struct string*)element);
}

void string_make_less(void* element) {
    int i = 0;
    
    while (((struct string*)element)->str[i] != '\0') {
        i += 1;
    }
    
    if (i != 0) {
        ((struct string*)element)->str[i-1] = '\0';
    }
}

//////////////////////////////////////////////

/*  SPECIAL FUNCTIONS TO CALL WITH WHERE */

bool more_than_10(void* element) {
    bool l;
    if (*(int*)element < 10) {
        l = false;
    }
    else {
        l = true;
    }
    return l;
}

bool less_than_10(void* element) {
    bool l;
    if (*(int*)element > 10) {
        l = false;
    }
    else {
        l = true;
    }
    return l;
}

bool larger_than_five(void* element) {
    bool l;
    int length = 0;
    while (((struct string*)element)->str[length] != '\0') {
        length += 1;
    }
    if (length >= 5) {
        l = true;
    }
    else {
        l = false;
    }
    return l;
}

bool smaller_than_five(void* element) {
    bool l;
    int length = 0;
    while (((struct string*)element)->str[length] != '\0') {
        length += 1;
    }
    if (length < 5) {
        l = true;
    }
    else {
        l = false;
    }
    return l;
}

//////////////////////////////////////////////

void massive_free(void** mass, int N) {
    int i;
    if (mass != NULL) {
        for (i = 0; i < N; i += 1) {
            free(*(mass + i));
        }
        free(mass);
    }
}
    
/*
 Error codes:
 1 - void massive after concat
*/

#endif
