#include <stdio.h>
#include <stdlib.h>

int* func1(void);
int* func2(void);

int main(int argc, char const *argv[])
{
    int* p = func1();
    printf("%p\n", p);
    printf("Deine Zahl auf dem Heap ist: %d\n", *p);
    free(p);
    

    //Array im Heap 
    int* arr_p = func2(); //Liefert Anfangsadresse auf den Stück Speicher im Heap für 20 Integer
    printf("Prüfe ob korrekt mit -1 initialisiert: %d\n", *arr_p);

    for(int i = 0; i < 20; i++)
    {
        arr_p[i] = i;
    }

    for(int i = 0; i < 20; i++)
    {
        printf("%d,", arr_p[i]);
    }
    printf("\n");

    free(arr_p);

    return 0;
}

int* func1(){

    int a = 23; 
    int *p = (int*)malloc(sizeof(int));
    printf("%p\n", p);
    *p = a; 

    return p;
}

int* func2(){

    //Allokiert für 20 Integer Speicher im Heap
    int* arr_p = (int*)malloc(sizeof(int) * 20);
    //Initialize
    for(int i = 0; i < 20; i++){
        arr_p[i] = -1;
    }

    return arr_p; 
}
