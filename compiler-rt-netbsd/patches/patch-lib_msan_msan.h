$NetBSD$

--- lib/msan/msan.h.orig	2017-06-03 23:53:56.000000000 +0000
+++ lib/msan/msan.h
@@ -178,7 +178,7 @@ const MappingDesc kMemoryLayout[] = {
 #define MEM_TO_SHADOW(mem) (LINEARIZE_MEM((mem)) + 0x080000000000ULL)
 #define SHADOW_TO_ORIGIN(shadow) (((uptr)(shadow)) + 0x140000000000ULL)
 
-#elif SANITIZER_FREEBSD && SANITIZER_WORDSIZE == 64
+#elif (SANITIZER_FREEBSD && SANITIZER_WORDSIZE == 64) || SANITIZER_NETBSD
 
 // Low memory: main binary, MAP_32BIT mappings and modules
 // High memory: heap, modules and main thread stack
