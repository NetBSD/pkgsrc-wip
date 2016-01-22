$NetBSD$

--- xpcom/base/Logging.h.orig	2016-01-22 10:25:27.000000000 +0000
+++ xpcom/base/Logging.h
@@ -7,6 +7,7 @@
 #ifndef mozilla_logging_h
 #define mozilla_logging_h
 
+#include <stdarg.h>
 #include <string.h>
 
 #include "prlog.h"
