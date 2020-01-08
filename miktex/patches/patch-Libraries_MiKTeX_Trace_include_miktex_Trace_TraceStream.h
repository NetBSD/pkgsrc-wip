$NetBSD$

Fix
error: 'va_list' has not been declared

--- Libraries/MiKTeX/Trace/include/miktex/Trace/TraceStream.h.orig	2019-11-16 19:20:48.000000000 +0000
+++ Libraries/MiKTeX/Trace/include/miktex/Trace/TraceStream.h
@@ -29,6 +29,7 @@
 #include <memory>
 #include <string>
 #include <vector>
+#include <stdarg.h>
 
 #include "TraceCallback.h"
 
