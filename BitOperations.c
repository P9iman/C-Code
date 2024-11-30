#include <stdio.h>

#define SECOND_FLAG 0b10
#define THIRD_FLAG 0b100
#define FIRST_FLAG 0b1

//Erstellt ein 32 Bit Feld wo das Bit an der Stelle N-1 gesetzt ist
#define CREATE_BIT_FIELD(N) ((1) << (N))

//NOTE: Mit N bestimmt man welches Flag gesetzt werden soll, dabei fängt man bei 0 an zu zählen!!
//Das heißt ist N=2, dann ist damit 0,1,2 -> das dritte Bit gemeint.
#define CLEAR_NTH_FLAG(FLAGS,N) ((FLAGS) &= ~(1 << (N)))

//Setzt ein Flag an einer beliebigen Stelle
#define SET_NTH_FLAG(FLAGS, N) ((FLAGS) |= (1 << N))

/**
 * https://www.includehelp.com/c-programs/define-macros-to-set-and-clear-bit-of-a-pin-in-c.aspx
 * 
*/
int main(int argc, char const *argv[])
{
    
    //Flags Variable
    int flags = SECOND_FLAG | THIRD_FLAG; //das 2 und 3 Flag sind am Anfangs schon gesetzt

    for (int i = 0; i < 2; i++)
    {
        //Wenn true dann wird eine 1 was wiederum true bedeutet ausgegeben 
        if (flags & FIRST_FLAG)
        {
            printf("Das erste Flag ist gesetzt!\n");
            printf("Binär: 0b%d\n", flags);
        }else{
            printf("Das erste Flag ist nicht gesetzt!\n");
            //Setze das erste Flag
            //Mit dem OR-Operator haben wir von der Flag Variable das erste Flag gesetzt und die anderen so gelassen 
            flags = flags | FIRST_FLAG;
        }
    }

    //Bitfield mittels einem Makro erstellen
    printf("Flag wurde an Stelle 6 gesetzt, entspricht dezimal %d\n", CREATE_BIT_FIELD(6));
    
    unsigned int newBitField = 0;
    printf("Flag 2 wird gesetzt, entspricht %d\n", SET_NTH_FLAG(newBitField, 2));

    //Flags löschen mittels AND und NOT
    unsigned int flags2 = 0b1000101;
    printf("Neues Bitfield, entspricht dezimal: %d\n", flags2);    


    unsigned int flags3 = flags2 & ~THIRD_FLAG;
    printf("Flag 3 wurde disabled (MANUEL), entspricht dezimal %d\n", flags3);

    //Mittels einem Makro    
    int disabled_second_flag = CLEAR_NTH_FLAG(flags2,2);
    printf("Flag 2 wurde disabled (MAKRO), entspricht dezimal %d\n",disabled_second_flag);
    
    return 0;
}
