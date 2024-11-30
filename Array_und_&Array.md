### Unterschied zwischen `array-Typ` und `&array-Typ`
---

Angenommen man hat eine Variable `int arr[] = {1,2,3}`.  
Wenn man diese Variable mittels dem Bezeichner `arr` nutzt, zerfällt (decays) der int-Array Typ zu einem Pointer-Typ.  
`arr` zeigt auf das erste Element des Arrays. 

**Beispiel:**
````C 
#include <stdio.h>

int arr[] = {1,2,3};
//Bei der übergabe von arr an printf, zerfällt 
//int arr[] zu &int[0]    
printf("Erst Element von arr: %d\n", *arr);
````

Setzt man ein `&` vor dem Bezeichner `arr` erhält man einen Pointer, der auf das gesammte Array zeigt.  
Also: `&arr` $\longleftrightarrow$ `int(*)[3]`    
Manchmal arbeitet man versehntlich mit dem falschen Typ und erhält, dann vom Compiler oder von der IDE, die Fehlermeldung:  
`Incompatible pointer types initializing 'int *' with an Expression von type 'int(*)[5]'`  
Das ist damit gemeint. Solche Fehler passieren häufig wenn man mit mehrdimensionalen Arrays arbeitet.

