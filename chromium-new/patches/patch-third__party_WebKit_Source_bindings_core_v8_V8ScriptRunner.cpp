$NetBSD$

--- third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp.orig	2016-11-10 20:02:25.000000000 +0000
+++ third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp
@@ -46,6 +46,8 @@
 
 #if OS(WIN)
 #include <malloc.h>
+#elif OS(FREEBSD) || OS(NETBSD)
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
