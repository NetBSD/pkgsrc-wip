$NetBSD$

Defines for DragonflyBSD and for arm.

--- code/qcommon/q_platform.h.orig	2017-04-28 09:13:25.000000000 +0000
+++ code/qcommon/q_platform.h
@@ -201,7 +201,7 @@ Foundation, Inc., 51 Franklin St, Fifth 
 
 //=================================================================== BSD ===
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 
 #include <sys/types.h>
 #include <machine/endian.h>
@@ -216,6 +216,8 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #define OS_STRING "openbsd"
 #elif defined(__NetBSD__)
 #define OS_STRING "netbsd"
+#elif defined(__DragonFly__)
+#define OS_STRING "dragonfly"
 #endif
 
 #define ID_INLINE inline
@@ -229,6 +231,8 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #define ARCH_STRING "x86_64"
 #elif defined __axp__
 #define ARCH_STRING "alpha"
+#elif defined __arm__
+#define ARCH_STRING "arm"
 #endif
 
 #if BYTE_ORDER == BIG_ENDIAN
