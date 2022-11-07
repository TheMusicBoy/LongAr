#ifndef _VALUES_
#define _VALUES_

#include"export.hpp"

#if __cplusplus >= 201700L
   #define LA_NODISCARD [[nodiscard]]
#elif __has_cpp_attribute(gnu::warn_unused_result)
   #define LA_NODISCARD [[gnu::warn_unused_result]]
#endif

#endif