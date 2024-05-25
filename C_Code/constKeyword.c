#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    
                            /*############ const Keyword in C ############*/
    char ch = 'a';
    /*
        Der Pointer ist konstant, er kann NICHT auf eine ander Speicherstelle zeigen.
    */
    char *const const_ptr = &ch;
    //Geht nicht: 
    // char chNeu = 'b';
    // const_ptr = &chNeu;
    //Aber man kann den Wert hinter dem Pointer ändern
    printf("ch: %c\n", ch);
    *const_ptr = 'A';
    printf("ch (modified): %c\n", ch);


    char ch2 = 'b';
    /*
        Der Wert hinter dem Pointer ist konstant, man kann ihn nicht verändern.
    */
    char const *ptr_to_const = &ch2;
    //Alternativ kann man den Typ auch anders schreiben: const bezieht sich hier auf das char nicht auf den Ptr!
    const char *ptr_to_const_2 = &ch2;
    //Geht nicht:
    // *ptr_to_const = 'd';
    //Aber man kann den Pointer auf eine andere Speicherstelle zeigen lassen
    char ch3 = 'X';
    printf("ptr_to_const zeigt auf: %p mit Value: %c\n", ptr_to_const, *ptr_to_const);
    ptr_to_const = &ch3;
    printf("ptr_to_const(modified) zeigt auf: %p mit Value: %c\n", ptr_to_const, *ptr_to_const);


    /* 
        Der Ptr kann nicht auf eine andere Speicherstelle zeigen.
        Der Wert hinter dem Ptr kann auch nicht verändert werden.
    */
    const char *const const_ptr_to_const = &ch2;
    //Alternativ (semantisch das gleiche): 
    //char const *const constant_ptr_to_const = &ch2;

    
//  A summary of the different types of pointers we can create and what
// is mutable/immutable (i.e. changable vs. unchangable).
//
//
//                         Pointer      Value
//
//  Non-Const Pointer      Mutable      Mutable
//  To Non-Const
//
//  Non-Const Pointer      Mutable      Immutable
//  To Const
//
//  Const Pointer          Immutable    Mutable
//  To Non-Const
//
//  Const Pointer          Immutable    Immutable
//  To Const
    return 0;
}
