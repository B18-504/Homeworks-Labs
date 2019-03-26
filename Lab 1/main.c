#include "dyn.h"

int main(void) {
    void **ints1 = NULL, **ints2 = NULL, **str1 = NULL, **str2 = NULL, **cint = NULL, **cstr = NULL;
    int N1, N2, N3, N4, choice;
    
    printf("///Creating 2 int massives///\n");
    printf("N1: ");
    scanf("%d", &N1);
    printf("Auto/Keyboard? (1/0): ");
    scanf("%d", &choice);
    while ((choice < 0) || (choice > 1)) {
        printf("***CHOICE ERROR***\n");
        printf("Auto/Keyboard? (1/0): ");
        scanf("%d", &choice);
    }
    getchar();
    if (choice == 0) {
        ints1 = int_massive_set_keyboard(ints1, N1);
    }
    else {
        ints1 = int_massive_set_auto(ints1, N1);
    }
    printf("N2: ");
    scanf("%d", &N2);
    printf("Auto/Keyboard? (1/0): ");
    scanf("%d", &choice);
    while ((choice < 0) || (choice > 1)) {
        printf("***CHOICE ERROR***\n");
        printf("Auto/Keyboard? (1/0): ");
        scanf("%d", &choice);
    }
    getchar();
    if (choice == 0) {
        ints2 = int_massive_set_keyboard(ints2, N2);
    }
    else {
        ints2 = int_massive_set_auto(ints2, N2);
    }
    
    printf("///Creating 2 string massives///\n");
    printf("N3: ");
    scanf("%d", &N3);
    printf("Auto/Keyboard? (1/0): ");
    scanf("%d", &choice);
    while ((choice < 0) || (choice > 1)) {
        printf("***CHOICE ERROR***\n");
        printf("Auto/Keyboard? (1/0): ");
        scanf("%d", &choice);
    }
    getchar();
    if (choice == 0) {
        str1 = string_massive_set_keyboard(str1, N3);
    }
    else {
        str1 = string_massive_set_auto(str1, N3);
    }
    printf("N4: ");
    scanf("%d", &N4);
    printf("Auto/Keyboard? (1/0): ");
    scanf("%d", &choice);
    while ((choice < 0) || (choice > 1)) {
        printf("***CHOICE ERROR***\n");
        printf("Auto/Keyboard? (1/0): ");
        scanf("%d", &choice);
    }
    getchar();
    if (choice == 0) {
        str2 = string_massive_set_keyboard(str2, N4);
    }
    else {
        str2 = string_massive_set_auto(str2, N4);
    }
    choice = 1;
    
    
    while (choice != 0) {
        printf("\n");
        printf("Operations:\n");
        printf("1. Sort every massive\n");
        printf("2. Concatination\n");
        printf("3. Map functions\n");
        printf("4. Where functions\n");
        printf("5. Print massives\n");
        printf("6. Reinitialize massives\n");
        printf("0. Exit\n");
        printf("Choice: ");
        
        scanf("%d", &choice);
        while ((choice < 0) || (choice > 6)) {
            printf("***CHOICE ERROR***\n");
            printf("Choice: ");
            scanf("%d", &choice);
        }
        getchar();
        printf("\n");
        
        if (choice == 0) {
            break;
        }
        
        if (choice == 1) {
            massive_sort(ints1, N1, int_massive_quicksort);
            massive_sort(ints2, N2, int_massive_quicksort);
            massive_sort(str1, N3, string_massive_quicksort);
            massive_sort(str2, N4, string_massive_quicksort);
            if (cint != NULL) {
                massive_sort(cint, N1+N2, int_massive_quicksort);
            }
            if (cstr != NULL) {
                massive_sort(cstr, N3+N4, string_massive_quicksort);
            }
            printf("Done\n");
        }
        
        if (choice == 2) {
            cint = massive_concat(ints1, N1, ints2, N2);
            cstr = massive_concat(str1, N3, str2, N4);
            printf("Ints1 + ints2: ");
            int_massive_print(cint, N1+N2);
            printf("\n");
            printf("Str1 + str2: ");
            string_massive_print(cstr, N3+N4);
            printf("\n");
            getchar();
        }
        
        if (choice == 3) {
            printf("Int/string massive? (1/0): ");
            scanf("%d", &choice);
            while ((choice < 0) || (choice > 1)) {
                printf("***CHOICE ERROR***\n");
                printf("Int/string massive? (1/0): ");
                scanf("%d", &choice);
            }
            getchar();
            
            if (choice == 1) {
                printf("List of functions:\n");
                printf("1. Int plus one\n");
                printf("2. Int minus ten\n");
                printf("Choice: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 2)) {
                    printf("***CHOICE ERROR***\n");
                    printf("Choice: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 1) {
                    map(ints1, N1, int_plus_one);
                    map(ints2, N2, int_plus_one);
                }
                else {
                    map(ints1, N1, int_minus_ten);
                    map(ints2, N2, int_minus_ten);
                }
            }
            else {
                printf("List of functions:\n");
                printf("1. String doubler\n");
                printf("2. String make less\n");
                printf("Choice: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 2)) {
                    printf("***CHOICE ERROR***\n");
                    printf("Choice: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 1) {
                    map(str1, N3, string_double);
                    map(str2, N4, string_double);
                }
                else {
                    map(str1, N3, string_make_less);
                    map(str2, N4, string_make_less);
                }
            }
            printf("Done\n");
            choice = 1;
        }
        
        if (choice == 4) {
            printf("Int/string massive? (1/0): ");
            scanf("%d", &choice);
            while ((choice < 0) || (choice > 1)) {
                printf("***CHOICE ERROR***\n");
                printf("Int/string massive? (1/0): ");
                scanf("%d", &choice);
            }
            getchar();
            
            if (choice == 1) {
                printf("List of sorting functions:\n");
                printf("1. Element is more than 10\n");
                printf("2. Element is less than 10\n");
                printf("Choice: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 2)) {
                    printf("***CHOICE ERROR***\n");
                    printf("Choice: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 1) {
                    ints1 = where(ints1, &N1, more_than_10);
                    ints2 = where(ints2, &N2, more_than_10);
                }
                else {
                    ints1 = where(ints1, &N1, less_than_10);
                    ints2 = where(ints2, &N2, less_than_10);
                }
            }
            else {
                printf("List of sorting functions:\n");
                printf("1. Element is larger than 5 chars\n");
                printf("2. Element is smaller than 5 chars\n");
                printf("Choice: ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 2)) {
                    printf("***CHOICE ERROR***\n");
                    printf("Choice: ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 1) {
                    str1 = where(str1, &N3, larger_than_five);
                    str2 = where(str2, &N4, larger_than_five);
                }
                else {
                    str1 = where(str1, &N3, smaller_than_five);
                    str2 = where(str2, &N4, smaller_than_five);
                }
            }
            printf("Done\n");
            choice = 1;
        }
        
        if (choice == 5) {
            printf("Int1: ");
            int_massive_print(ints1, N1);
            printf("\n");
            printf("Int2: ");
            int_massive_print(ints2, N2);
            printf("\n");
            printf("Str1: ");
            string_massive_print(str1, N3);
            printf("\n");
            printf("Str2: ");
            string_massive_print(str2, N4);
            printf("\n");
            if (cint != NULL) {
                printf("Concatinated ints: ");
                int_massive_print(cint, N1+N2);
                printf("\n");
            }
            if (cstr != NULL) {
                printf("Concatinated strs: ");
                string_massive_print(cstr, N1+N2);
                printf("\n");
            }
            getchar();
        }
        
        if (choice == 6) {
            printf("Which massive?:\n");
            printf("1. Ints1\n");
            printf("2. Ints2\n");
            printf("3. Str1\n");
            printf("4. Str2\n");
            printf("Choice: ");
            scanf("%d", &choice);
            while ((choice < 0) || (choice > 4)) {
                printf("***CHOICE ERROR***\n");
                printf("Choice: ");
                scanf("%d", &choice);
            }
            getchar();
            if (choice == 1) {
                printf("N1: ");
                scanf("%d", &N1);
                printf("Auto/Keyboard? (1/0): ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 1)) {
                    printf("***CHOICE ERROR***\n");
                    printf("Auto/Keyboard? (1/0): ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 0) {
                    ints1 = int_massive_set_keyboard(ints1, N1);
                }
                else {
                    ints1 = int_massive_set_auto(ints1, N1);
                }
            }
            if (choice == 2) {
                printf("N2: ");
                scanf("%d", &N2);
                printf("Auto/Keyboard? (1/0): ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 1)) {
                    printf("***CHOICE ERROR***\n");
                    printf("Auto/Keyboard? (1/0): ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 0) {
                    ints2 = int_massive_set_keyboard(ints2, N2);
                }
                else {
                    ints2 = int_massive_set_auto(ints2, N2);
                }
            }
            if (choice == 3) {
                printf("N3: ");
                scanf("%d", &N3);
                printf("Auto/Keyboard? (1/0): ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 1)) {
                    printf("***CHOICE ERROR***\n");
                    printf("Auto/Keyboard? (1/0): ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 0) {
                    str1 = string_massive_set_keyboard(str1, N3);
                }
                else {
                    str1 = string_massive_set_auto(str1, N3);
                }
            }
            if (choice == 4) {
                printf("N4: ");
                scanf("%d", &N4);
                printf("Auto/Keyboard? (1/0): ");
                scanf("%d", &choice);
                while ((choice < 0) || (choice > 1)) {
                    printf("***CHOICE ERROR***\n");
                    printf("Auto/Keyboard? (1/0): ");
                    scanf("%d", &choice);
                }
                getchar();
                if (choice == 0) {
                    str2 = string_massive_set_keyboard(str2, N4);
                }
                else {
                    str2 = string_massive_set_auto(str2, N4);
                }
            }
            printf("Done\n");
            choice = 1;
        }
    }
    
    massive_free(ints1, N1);
    massive_free(ints2, N2);
    massive_free(str1, N3);
    massive_free(str2, N4);
    massive_free(cint, N1+N2);
    massive_free(cstr, N1+N2);
    
    return 0;
}
