/*****************************************************************************/
/*                             main.cpp file                                 */
/* Including main, which calls a function throwing, defined in mylib         */
/*****************************************************************************/

#include "mylib.hpp"
#include <cstdio>

int main()
{
    printf("Calling ThrowingFunction\n");
    ThrowingFunction();
    printf("After calling ThrowingFunction\n");
    
    return 0;
}