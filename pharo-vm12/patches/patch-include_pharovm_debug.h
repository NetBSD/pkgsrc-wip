$NetBSD$

Need stdarg.h for va_list

--- include/pharovm/debug.h.orig	2023-03-18 09:15:22.487573163 +0000
+++ include/pharovm/debug.h
@@ -49,6 +49,7 @@ void error(char* aMessage);
 
 
 #include <stdio.h>
+#include <stdarg.h>
 
 int vm_printf(const char * format, ... );
 void vm_setVMOutputStream(FILE * stream);
