$NetBSD$

--- src/pal/src/cruntime/silent_printf.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/cruntime/silent_printf.cpp
@@ -26,6 +26,7 @@ Revision History:
 #include "pal/cruntime.h"
 #include "pal/locale.h"
 #include "pal/printfcpp.hpp"
+#include "pal/thread.hpp"
 
 /* clip strings (%s, %S) at this number of characters */
 #define MAX_STR_LEN 300
@@ -280,7 +281,7 @@ INT Silent_PAL_vsnprintf(LPSTR Buffer, I
                     }                                     
                     va_list apcopy;
                     va_copy(apcopy, ap);
-                    TempInt = PAL__vsnprintf(BufferPtr, TempCount, TempBuff, apcopy);
+                    TempInt = InternalVsnprintf(CorUnix::InternalGetCurrentThread(), BufferPtr, TempCount, TempBuff, apcopy);
                     va_end(apcopy);
                     PAL_printf_arg_remover(&ap, Width, Precision, Type, Prefix);
                 }
@@ -987,4 +988,3 @@ size_t Silent_PAL_wcslen(const wchar_16 
     
     return nChar;
 }
-
