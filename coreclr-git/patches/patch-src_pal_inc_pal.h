$NetBSD$

--- src/pal/inc/pal.h.orig	2016-01-21 12:20:13.000000000 +0000
+++ src/pal/inc/pal.h
@@ -3476,26 +3476,34 @@ PALIMPORT BOOL PALAPI PAL_VirtualUnwindO
 
 #ifdef PLATFORM_UNIX
 
-#if defined(__FreeBSD__) && defined(_X86_)
-#define PAL_CS_NATIVE_DATA_SIZE 12
-#elif defined(__FreeBSD__) && defined(__x86_64__)
-#define PAL_CS_NATIVE_DATA_SIZE 24
-#elif defined(__sun__)
-#define PAL_CS_NATIVE_DATA_SIZE 48
-#elif defined(__hpux__) && (defined(__hppa__) || defined (__ia64__))
-#define PAL_CS_NATIVE_DATA_SIZE 148
-#elif defined(_AIX)
+/* PAL_CS_NATIVE_DATA_SIZE == sizeof(PAL_CRITICAL_SECTION_NATIVE_DATA) */
+
+#if defined(_AIX)
 #define PAL_CS_NATIVE_DATA_SIZE 100
 #elif defined(__APPLE__) && defined(__i386__)
 #define PAL_CS_NATIVE_DATA_SIZE 76
 #elif defined(__APPLE__) && defined(__x86_64__)
 #define PAL_CS_NATIVE_DATA_SIZE 120
-#elif defined(__LINUX__) && defined(__x86_64__)
-#define PAL_CS_NATIVE_DATA_SIZE 96
+#elif defined(__FreeBSD__) && defined(_X86_)
+#define PAL_CS_NATIVE_DATA_SIZE 12
+#elif defined(__FreeBSD__) && defined(__x86_64__)
+#define PAL_CS_NATIVE_DATA_SIZE 24
+#elif defined(__hpux__) && (defined(__hppa__) || defined (__ia64__))
+#define PAL_CS_NATIVE_DATA_SIZE 148
 #elif defined(__LINUX__) && defined(_ARM_)
 #define PAL_CS_NATIVE_DATA_SIZE 80
 #elif defined(__LINUX__) && defined(_ARM64_)
 #define PAL_CS_NATIVE_DATA_SIZE 116
+#elif defined(__LINUX__) && defined(__x86_64__)
+#define PAL_CS_NATIVE_DATA_SIZE 96
+#elif defined(__NetBSD__) && defined(__amd64__)
+#define PAL_CS_NATIVE_DATA_SIZE 96
+#elif defined(__NetBSD__) && defined(__earm__)
+#define PAL_CS_NATIVE_DATA_SIZE 56
+#elif defined(__NetBSD__) && defined(__i386__)
+#define PAL_CS_NATIVE_DATA_SIZE 56
+#elif defined(__sun__)
+#define PAL_CS_NATIVE_DATA_SIZE 48
 #else 
 #warning 
 #error  PAL_CS_NATIVE_DATA_SIZE is not defined for this architecture
