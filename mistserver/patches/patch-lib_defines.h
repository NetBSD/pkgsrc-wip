$NetBSD$

NetBSD support

--- lib/defines.h.orig	2026-07-14 14:33:43.417815112 +0000
+++ lib/defines.h
@@ -46,7 +46,7 @@ static const char *DBG_LVL_LIST[] ={"NON
 #endif
 
 // Find program name best we can
-#if defined(__APPLE__) || defined(__MACH__)
+#if defined(__APPLE__) || defined(__MACH__) || defined(__NetBSD__)
 #include <stdlib.h>
 #define MIST_PROG getprogname()
 #else
