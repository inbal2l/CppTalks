/*****************************************************************************/
/*                             mylib.hpp file                                */
/* Including MyException definition struct created when calling throw.       */
/*****************************************************************************/

#include <cstdio>
#include <string.h>

#define STR_SIZE 64

struct MyException {
    MyException(char *name_) {  
        strncpy(name, name_, STR_SIZE);
        printf("MyException: %s CTOR\n", name);
    }
    ~MyException() {
        printf("MyException: %s DTOR\n", name);  
    }
    char name[STR_SIZE];   
 };

void ThrowingFunction();