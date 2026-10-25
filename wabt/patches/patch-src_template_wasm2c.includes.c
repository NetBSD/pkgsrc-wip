$NetBSD$

* Fix include on NetBSD for alloca

--- src/template/wasm2c.includes.c.orig	2026-10-25 13:58:14.909779911 +0000
+++ src/template/wasm2c.includes.c
@@ -9,7 +9,7 @@
 #include <intrin.h>
 #include <malloc.h>
 #define alloca _alloca
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <stdlib.h>
 #else
 #include <alloca.h>
