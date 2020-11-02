$NetBSD$

setresuid/setresguid are not supported on NetBSD.

--- doas.c.orig	2020-11-02 14:26:25.771778844 +0000
+++ doas.c
@@ -34,6 +34,11 @@
 #include "includes.h"
 #include "doas.h"
 
+#ifdef __netbsd__
+#define setresgid(a, b, c)     setgid(a)
+#define setresuid(a, b, c)     setuid(a)
+#endif
+
 static void __dead
 usage(void)
 {
