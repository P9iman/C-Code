#include <stdio.h>

int main(int argc, char const *argv[])
{

    unsigned int a = 1; 
    
    //Left shift operations
    printf("1 Left shifted by 1: %d\n", a << 1);
    printf("1 Left shifted by 4: %d\n", 1 << 4);

    printf("5 Left shiftet by 1; %d\n", 5 << 1);
    printf("5 Left shiftet by 5; %d\n", 5 << 5);

    //Right shift operations
    //5 = 0101 -> 5>>1 -> 0010 = 2
    printf("5 Right shiftet by 1; %d\n", 5 >> 1);
    printf("5 Right shiftet by 5; %d\n", 5 >> 5);


    return 0;
}
