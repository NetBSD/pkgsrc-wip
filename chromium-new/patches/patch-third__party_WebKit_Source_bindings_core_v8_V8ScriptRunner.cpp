$NetBSD$

--- third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp.orig	2016-06-24 01:02:44.000000000 +0000
+++ third_party/WebKit/Source/bindings/core/v8/V8ScriptRunner.cpp
@@ -43,6 +43,8 @@
 
 #if OS(WIN)
 #include <malloc.h>
+#elif OS(FREEBSD) || defined(OS_NETBSD)
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
