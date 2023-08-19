$NetBSD$

APK does not have extern in their files.

--- src/apk_defines.h.orig	2023-08-18 20:32:45.674938175 +0000
+++ src/apk_defines.h
@@ -16,6 +16,8 @@
 #include <errno.h>
 #include <time.h>
 
+extern char** environ;
+
 #define ARRAY_SIZE(x)	(sizeof(x) / sizeof((x)[0]))
 #define BIT(x)		(1U << (x))
 #define min(a, b)	((a) < (b) ? (a) : (b))
