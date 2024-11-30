#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /**
     * Strings in C haben als letztes Zeichen den Null-Character ('\0'), der automatisch am Ende hinzugefügt wird.
     * Dieser deutet auf das Ende des Strings hin, wenn man über den String iteriert und vllt. manipuliert.
    */

    /**
     * String Literale:
     * "Hallo" ist ein sog. String-Literal. Die einzelnen Character werden in dieser Reihenfolge im 
     * Hauptspeichers abgelegt inkl. des Null-Char.
    */

    //Char-Array befindet sich auf dem Stack. Dinge die sich auf dem Stack befinden können verändert werden.
    char str1[] = "Hallo";
    str1[4] = 'A';

    printf("str1: %s\n", str1); //str1 wird in ein const Pointer umgewandelt und printf übergeben.

    /*
        Bei der Umwandlung eines Arrays in ein Pointer auf das erste Element, wird daraus ein const <Typ> * generiert
        Deshalb kann man den Pointer auch nicht manipulieren. Der Wert hinter dem Pointer kann man aber weiterhin verändern 
    */ 
    //str1++; nicht möglich

    //KEIN CHAR-ARRAY. Ein Pointer auf den ersten Character des String-Literal.
    //Laut C-Standard ist nicht genau definiert wo sich das String-Literal im Hauptspeicher befindet. 
    char *str2 = "Hallo";
    
    //C erlaubt zwar diese Manipulation, jedoch führt der Zugriff zur Laufzeit zu einem Seg-Fault.
    // str2[4] = 'A'; //Segmentation Fault
    /*
        Wenn man schon zur Compile-Zeit diesen versehntlichen Fehler abfangen möchte, dann sollte man Variablen
        vom Typ char* immer mit const deklarieren, wenn man ein String-Literal abspeichern möchte.
        Hierdurch wird der Wert hinter dem Ptr unveränderlich. 
    */
    const char *str2Neu = "Mein string";      
    // str2Neu[0] = 's'; //führt zu einem Compile-Error

    //Da str2 auf das erste Zeichen von Hallo zeigt, ist Pointer-Arithmetik möglich. 
    str2++;
    printf("str2: %s\n", str2);

    /*### Weitere Unterschiede zwischen char* und char <>[] ###*/
    
    /*Überschreiben eines Strings*/
    
    char str3[] = "Test";
    printf("str3: %s\n", str3);
    /*
        Geht nicht da str3 umgewandelt ein const <Typ>* (Const-Ptr) ist.
        Hier wird versucht str3 auf eine neue Speicherstelle zeigen zu lassen.
    */
    // str3 = "Test2";
    /*Mit der Funktion strcpy/strncpy kann man str3 neu setzen*/    
    strcpy(str3, "TEST"); //str3 muss genügend Platz für das neue String-Literal haben! Sonst Buffer-Overflow
    printf("str3 (modified mit strcpy): %s\n", str3);


    char* str4 = "Test";
    printf("str4: %s\n", str4);
    /*
        Geht problemlos, da es sich bei str4 um einen veränderbaren Pointer handelt.
        Der Pointer zeigt einfach auf eine neue Speicherstelle.
    */
    str4 = "TEST";   
    printf("str4 (modified mit Zuweisung): %s\n", str4);
    // str4[0] = 'X'; //geht nicht, da der Wert hinter dem Ptr konstant ist. 

    printf("sizeof(str3): %ld\n", sizeof(str3)); //Liefert Anzahl an char in dem String-Literalt incl. Null-Char
    printf("sizeof(str4): %ld\n", sizeof(str4)); //Liefert die Größe des Ptr auf dem Stack
    return 0;
}
