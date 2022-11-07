#ifndef _EXPORT_
#define _EXPORT_

#ifndef __linux__
   #ifdef BIG_INT_EXPORTS
      #define BIG_INT_API __declspec(dllexport)
   #else
      #define BIG_INT_API __declspec(dllinport)
   #endif
#else
   #define BIG_INT_API
#endif

#endif