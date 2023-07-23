$NetBSD$

# Portability

--- SharedMemory.cpp.orig	2023-07-23 17:37:47.154665669 +0000
+++ SharedMemory.cpp
@@ -12,7 +12,7 @@
 #include <errno.h>
 #include <sys/types.h>
 
-#if defined(COMPILE_FOR_MAC) || defined(__FreeBSD__)
+#if defined(COMPILE_FOR_MAC) || defined(__FreeBSD__) || defined(__NetBSD__)
   //some Mac's idiosyncrasies: standard SHM libraries are very old and missing some definitions
   #define SHM_NORESERVE 0
 #endif
