$NetBSD: patch-src_armcpu.h,v 1.1 2013/12/19 03:25:57 othyro Exp $

Relocated patch for src/firmware.cpp to here. Source file changed.

--- src/armcpu.h.orig	2013-11-28 00:37:18.000000000 +0000
+++ src/armcpu.h
@@ -55,12 +55,15 @@ inline T SIGNED_OVERFLOW(T a,T b,T c) { 
 template<typename T>
 inline T SIGNED_UNDERFLOW(T a,T b,T c) { return BIT31(((a)&(~(b))&(~c)) | ((~a)&(b)&(c))); }
 
+#if !defined(bswap32)
 #define bswap32(val) \
 			( (val << 24) & 0xFF000000) | \
 			( (val <<  8) & 0x00FF0000) | \
 			( (val >>  8) & 0x0000FF00) | \
 			( (val >> 24) & 0x000000FF) 
+#endif
 
+#if !defined(bswap64)
 #define bswap64(x) \
 			( (x << 56) & 0xff00000000000000ULL ) | \
 			( (x << 40) & 0x00ff000000000000ULL ) | \
@@ -70,6 +73,7 @@ inline T SIGNED_UNDERFLOW(T a,T b,T c) {
 			( (x >> 24) & 0x0000000000ff0000ULL ) | \
 			( (x >> 40) & 0x000000000000ff00ULL ) | \
 			( (x >> 56) & 0x00000000000000ffULL ) 
+#endif
 
 // ============================= CPRS flags funcs
 inline bool CarryFrom(s32 left, s32 right)
