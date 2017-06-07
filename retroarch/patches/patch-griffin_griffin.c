$NetBSD$

Use the Linux frontend on BSD since the BSD frontend is incomplete.

--- griffin/griffin.c.orig	2017-05-31 23:25:41.000000000 +0000
+++ griffin/griffin.c
@@ -782,10 +782,8 @@ FRONTEND
 #include "../frontend/drivers/platform_xenon.c"
 #elif defined(__QNX__)
 #include "../frontend/drivers/platform_qnx.c"
-#elif defined(__linux__)
+#elif defined(__linux__) || (defined(BSD) && !defined(__MACH__))
 #include "../frontend/drivers/platform_linux.c"
-#elif defined(BSD) && !defined(__MACH__)
-#include "../frontend/drivers/platform_bsd.c"
 #elif defined(DJGPP)
 #include "../frontend/drivers/platform_dos.c"
 #endif
