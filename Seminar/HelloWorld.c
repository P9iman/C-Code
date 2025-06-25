#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a = 20;
    int* a_ptr = (int*)malloc(sizeof(int));
    *a_ptr = a; //Speicher a im Heap

    int* x = a_ptr; // hier würde in Rust ein move passieren 
    //Genau das erlaubt Rust nicht! Da es sonst zu den gennanten Problemen führt
    int* y = a_ptr; // hier würde es einen Compiler-Fehler geben, da a_ptr gemoved wurde!

    
    printf("a_ptr is = %d\n", *a_ptr);
    free(a_ptr);
    //Ab hier sind x und y Dangling Pointer! da auf a_ptr free() aufgerufen wurde 

    printf("x points to %d\n", *x); //undefined Behaviour

    return 0;
}
