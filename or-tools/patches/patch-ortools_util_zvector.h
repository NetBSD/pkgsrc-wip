$NetBSD$

https://github.com/google/or-tools/issues/4359

--- ortools/util/zvector.h.orig	2024-08-27 13:35:44.000000000 +0000
+++ ortools/util/zvector.h
@@ -14,7 +14,7 @@
 #ifndef OR_TOOLS_UTIL_ZVECTOR_H_
 #define OR_TOOLS_UTIL_ZVECTOR_H_
 
-#if (defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)) && \
+#if (defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) ) && \
     defined(__GNUC__)
 #include <machine/endian.h>
 #elif !defined(_MSC_VER) && !defined(__MINGW32__) && !defined(__MINGW64__)
