$NetBSD$

DragonFly BSD already has closefrom defined in unistd.h

--- compat/compat.h.orig	2019-10-12 15:07:28.000000000 +0000
+++ compat/compat.h
@@ -1,7 +1,7 @@
 #include <sys/types.h>
 #include <stdarg.h>
 
-#if !defined(__NetBSD__)
+#if !defined(__NetBSD__) && !defined(__DragonFly__)
 void closefrom(int lowfd);
 #endif
 
