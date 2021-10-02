/*****************************************************************************/
/*                           newlibstdcpp.cpp file                           */
/* Including overloaded libstdc++ functions.                                 */
/*****************************************************************************/

#include <cstdio>
#include <typeinfo>

#include "newlibstdcpp.hpp"

#define BUFF_SIZE 1024
char buff[BUFF_SIZE];

void* __cxa_allocate_exception(size_t thrown_size) {
    printf("__cxa_allocate_exception called\n");    
    printf("Allocating Exception: %lu B\n", thrown_size);
    if (thrown_size > BUFF_SIZE) { 
        printf("Exception overflow! Terminating...");
        std::exit(EXIT_FAILURE);        // ABI determin using std::terminate, replaced it with exit to avoid including <exception>
    }
    return &buff;
}

void __cxa_throw(
          void* thrown_exception,
          struct std::type_info *tinfo,
          void (*dest)(void*))  {
    printf("__cxa_throw called\n");
    printf("Exiting...\n");
    std::exit(EXIT_SUCCESS);    
}

