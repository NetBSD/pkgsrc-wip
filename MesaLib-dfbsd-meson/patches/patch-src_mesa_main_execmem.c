$NetBSD$

--- src/mesa/main/execmem.c.orig	2019-03-23 16:29:21.000000000 +0000
+++ src/mesa/main/execmem.c
@@ -37,7 +37,20 @@
 #include "c11/threads.h"
 
 
-#if defined(__linux__) || defined(__OpenBSD__) || defined(_NetBSD__) || defined(__sun) || defined(__HAIKU__)
+#if defined(DISABLE_WX_MEMORY)
+
+void *
+_mesa_exec_malloc(GLuint size)
+{
+   return NULL;
+}
+
+void
+_mesa_exec_free(void *addr)
+{
+}
+
+#elif defined(__linux__) || defined(__OpenBSD__) || defined(_NetBSD__) || defined(__sun) || defined(__HAIKU__)
 
 /*
  * Allocate a large block of memory which can hold code then dole it out
