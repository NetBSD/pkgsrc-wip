$NetBSD$

--- lib/msan/msan.h.orig	2017-10-17 18:35:51.000000000 +0000
+++ lib/msan/msan.h
@@ -199,7 +199,7 @@ const MappingDesc kMemoryLayout[] = {
 #define MEM_TO_SHADOW(mem) (LINEARIZE_MEM((mem)) + 0x100000000000ULL)
 #define SHADOW_TO_ORIGIN(shadow) (((uptr)(shadow)) + 0x280000000000)
 
-#elif SANITIZER_LINUX && SANITIZER_WORDSIZE == 64
+#elif SANITIZER_LINUX && SANITIZER_WORDSIZE == 64 || SANITIZER_NETBSD
 
 #ifdef MSAN_LINUX_X86_64_OLD_MAPPING
 // Requries PIE binary and ASLR enabled.
