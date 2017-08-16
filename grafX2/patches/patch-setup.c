$NetBSD$

Don't discriminate against unix-like systems.

--- setup.c.orig	2012-12-05 00:18:04.000000000 +0000
+++ setup.c
@@ -39,7 +39,7 @@
 #elif defined(__MINT__)
     #include <mint/osbind.h>
     #include <mint/sysbind.h>
-#elif defined(__linux__)
+#else
   #include <limits.h>
   #include <unistd.h>
 #endif
