$NetBSD: patch-executable_path.c,v 1.0 2024/05/06 14:00:00 dkazankov Exp $

Add NetBSD support

--- core/src/executable_path.c.orig	2024-09-24 12:28:32.000000000 +0300
+++ core/src/executable_path.c
@@ -50,7 +50,7 @@
     return (int) GetModuleFileNameA(NULL, buffer, (DWORD) size);
 }
 
-#elif defined (__linux__)
+#elif defined (__linux__) || defined (__NetBSD__)
 /* Linux implementation */
 #include <unistd.h>
 int
