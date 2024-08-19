$NetBSD$

NetBSD support.

--- folly/debugging/symbolizer/Elf.cpp.orig	2024-08-19 19:44:58.370813805 +0000
+++ folly/debugging/symbolizer/Elf.cpp
@@ -40,7 +40,7 @@
 
 #if defined(__ELF_NATIVE_CLASS)
 #define FOLLY_ELF_NATIVE_CLASS __ELF_NATIVE_CLASS
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD_)
 #if defined(__LP64__)
 #define FOLLY_ELF_NATIVE_CLASS 64
 #else
