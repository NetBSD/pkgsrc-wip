$NetBSD$

--- base/trace_event/malloc_dump_provider.cc.orig	2016-11-10 20:02:09.000000000 +0000
+++ base/trace_event/malloc_dump_provider.cc
@@ -20,7 +20,7 @@
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 #if defined(OS_WIN)
 #include <windows.h>
