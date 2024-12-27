$NetBSD$

alloca.h is linux specific.
Define ARCH_STRING for *BSD on x86_64.

--- code/qcommon/q_platform.h.orig	2024-12-27 07:51:08.003536135 +0000
+++ code/qcommon/q_platform.h
@@ -89,7 +89,8 @@ Foundation, Inc., 51 Franklin St, Fifth 
 // alloca
 #ifdef _MSC_VER
 #  include <malloc.h>
-#else
+#endif
+#ifdef __linux__
 #  include <alloca.h>
 #endif
 
@@ -313,6 +314,9 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #elif defined __axp__
 #define ARCH_STRING "alpha"
 #endif
+#if defined(__x86_64) || defined(__x86_64__) || defined(__amd64) || defined(_M_X64)
+#define ARCH_STRING "x86_64"
+#endif
 
 #if __BIG_ENDIAN__
 #  define Q3_BIG_ENDIAN
