$NetBSD$

--- src/tools/singlejar/diag.h.orig	2023-11-29 01:42:21.128823620 +0000
+++ src/tools/singlejar/diag.h
@@ -20,7 +20,7 @@
  * for portability.
  */
 #if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || \
-    defined(__OpenBSD__)
+    defined(__OpenBSD__) || defined(__NetBSD__)
 
 #include <err.h>
 #define diag_err(...) err(__VA_ARGS__)
