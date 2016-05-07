$NetBSD$

--- src/Native/gc/env/gcenv.base.h.orig	2016-05-07 12:28:59.774660421 +0000
+++ src/Native/gc/env/gcenv.base.h
@@ -24,8 +24,12 @@
 #endif // __clang__
 #endif // !_MSC_VER
 
+#ifndef SIZE_T_MAX
 #define SIZE_T_MAX ((size_t)-1)
+#endif
+#ifndef SSIZE_T_MAX
 #define SSIZE_T_MAX ((ptrdiff_t)(SIZE_T_MAX / 2))
+#endif
 
 #ifndef _INC_WINDOWS
 // -----------------------------------------------------------------------------------------------------------
