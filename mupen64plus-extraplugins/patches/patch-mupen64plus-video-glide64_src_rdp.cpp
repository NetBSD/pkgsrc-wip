$NetBSD: patch-mupen64plus-video-glide64_src_rdp.cpp,v 1.1 2013/07/07 12:48:16 othyro Exp $

Don't redefine bswap32().

--- mupen64plus-video-glide64/src/rdp.cpp.orig	2013-07-05 02:18:45.000000000 +0000
+++ mupen64plus-video-glide64/src/rdp.cpp
@@ -67,12 +67,12 @@ int wrong_tile = -1;
 
 int drawFlag = 1;	// draw flag for rendering callback
 
-#if defined(__GNUC__)
+#if defined(__GNUC__) && !defined(_SYS_BSWAP_H_)
   #define bswap32(x) __builtin_bswap32(x)
 #elif defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))
   #include <stdlib.h>
   #define bswap32(x) _byteswap_ulong(x)
-#else
+#elseif !defined(_SYS_BSWAP_H_)
 static inline uint32_t bswap32(uint32_t val)
 {
         return (((val & 0xff000000) >> 24) |
