$NetBSD$

Need stdarg.h for va_list

--- include/pharovm/debug.h.orig	2021-11-04 14:38:36.845945841 +0000
+++ include/pharovm/debug.h
@@ -46,6 +46,7 @@ EXPORT(int) isLogDebug();
 EXPORT(void) logMessageFromErrno(int level, const char* msg, const char* fileName, const char* functionName, int line);
 
 #include <stdio.h>
+#include <stdarg.h>
 
 int vm_printf(const char * format, ... );
 void vm_setVMOutputStream(FILE * stream);
