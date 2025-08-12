$NetBSD$

--- spa/plugins/support/logger.c.orig	2025-07-29 19:25:58.121117580 +0000
+++ spa/plugins/support/logger.c
@@ -20,7 +20,7 @@
 #include <spa/utils/string.h>
 #include <spa/utils/ansi.h>
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__NetBSD__)
 #define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
 #elif defined(_MSC_VER)
 static inline void setlinebuf(FILE* stream) {
