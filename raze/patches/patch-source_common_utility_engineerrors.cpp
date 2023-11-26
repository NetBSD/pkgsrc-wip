$NetBSD$

Include cstdarg for va_list (exposed by turning pre-compiled headers off).

--- source/common/utility/engineerrors.cpp.orig	2023-11-12 13:35:34.000000000 +0000
+++ source/common/utility/engineerrors.cpp
@@ -74,6 +74,7 @@ void I_DebugPrintf(const char *fmt,...)
 }
 #endif
 
+#include <cstdarg>
 #include "engineerrors.h"
 
 //==========================================================================
