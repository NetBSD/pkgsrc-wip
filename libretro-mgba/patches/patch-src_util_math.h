$NetBSD$

NetBSD defines popcount32 in libc

--- src/util/math.h.orig	2017-03-29 18:42:18.000000000 +0000
+++ src/util/math.h
@@ -8,11 +8,15 @@
 
 #include "util/common.h"
 
+#ifndef __NetBSD__
 static inline uint32_t popcount32(unsigned bits) {
 	bits = bits - ((bits >> 1) & 0x55555555);
 	bits = (bits & 0x33333333) + ((bits >> 2) & 0x33333333);
 	return (((bits + (bits >> 4)) & 0xF0F0F0F) * 0x1010101) >> 24;
 }
+#else
+unsigned int popcount32(uint32_t);
+#endif
 
 static inline unsigned clz32(uint32_t bits) {
 #if defined(__GNUC__) || __clang__
