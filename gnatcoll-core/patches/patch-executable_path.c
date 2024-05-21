$NetBSD: patch-executable_path.c,v 1.0 2024/05/06 14:00:00 dkazankov Exp $

Add NetBSD support

--- src/executable_path.c.orig	2023-09-21 18:57:14.000000000 +0300
+++ src/executable_path.c	2024-05-06 13:54:06.462078706 +0300
@@ -50,7 +50,7 @@
     return (int) GetModuleFileNameA(NULL, buffer, (DWORD) size);
 }
 
-#elif defined (__linux__)
+#elif defined (__linux__) || defined (__NetBSD__)
 /* Linux implementation */
 #include <unistd.h>
 int
