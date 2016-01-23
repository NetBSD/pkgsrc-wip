# Needed for va_list later used in this file

--- xpcom/base/Logging.h.orig	2016-01-21 15:05:53.000000000 +0100
+++ xpcom/base/Logging.h	2016-01-21 15:36:24.000000000 +0100
@@ -7,6 +7,7 @@
 #ifndef mozilla_logging_h
 #define mozilla_logging_h
 
+#include <stdarg.h>
 #include <string.h>
 
 #include "prlog.h"
