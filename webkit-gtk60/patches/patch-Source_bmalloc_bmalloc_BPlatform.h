$NetBSD$

--- Source/bmalloc/bmalloc/BPlatform.h.orig	2025-08-08 09:17:56.268456700 +0000
+++ Source/bmalloc/bmalloc/BPlatform.h
@@ -60,6 +60,10 @@
 #define BOS_FREEBSD 1
 #endif
 
+#if defined(__NetBSD__)
+#define BOS_NETBSD 1
+#endif
+
 #if defined(WIN32) || defined(_WIN32)
 #define BOS_WINDOWS 1
 #endif
@@ -349,7 +353,7 @@
 
 /* BENABLE(LIBPAS) is enabling libpas build. But this does not mean we use libpas for bmalloc replacement. */
 #if !defined(BENABLE_LIBPAS)
-#if BCPU(ADDRESS64) && (BOS(DARWIN) || BOS(WINDOWS) || (BOS(LINUX) && (BCPU(X86_64) || BCPU(ARM64))) || BPLATFORM(PLAYSTATION))
+#if BCPU(ADDRESS64) && (BOS(DARWIN) || BOS(WINDOWS) || ((BOS(LINUX) || BOS(NETBSD)) && (BCPU(X86_64) || BCPU(ARM64))) || BPLATFORM(PLAYSTATION))
 #define BENABLE_LIBPAS 1
 #ifndef PAS_BMALLOC
 #define PAS_BMALLOC 1
