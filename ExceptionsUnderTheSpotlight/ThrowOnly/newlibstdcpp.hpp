/*****************************************************************************/
/*                           newlibstdcpp.hpp file                           */
/* Including decleration of overloaded libstdc++ functions.                  */
/*****************************************************************************/

#include <cstdlib>

extern "C" {

void* __cxa_allocate_exception(size_t thrown_size);
void __cxa_throw(void* thrown_exception, struct std::type_info *tinfo, void (*dest)(void*));

} 
