$NetBSD$

Fix va_list error

--- jsfriendapi.h.orig	2020-09-25 09:22:52.000000000 +0000
+++ jsfriendapi.h
@@ -14,6 +14,7 @@
 #include "mozilla/PodOperations.h"
 #include "mozilla/UniquePtr.h"
 
+#include <stdarg.h>
 #include "jspubtd.h"
 
 #include "js/CallArgs.h"
