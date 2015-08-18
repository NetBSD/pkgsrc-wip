$NetBSD: patch-src_libtcod_src_console_c.c,v 1.1 2015/08/18 20:24:52 yhardy Exp $

bswap16 and bswap32 are already defined in NetBSD

--- src/libtcod-1.5.2/src/console_c.c.orig	2014-07-03 19:19:10.000000000 +0000
+++ src/libtcod-1.5.2/src/console_c.c
@@ -43,6 +43,10 @@ static const char *version_string ="libt
 static const char *version_string __attribute__((unused)) ="libtcod "TCOD_STRVERSION;
 #endif
 
+#if defined(__NetBSD__)
+#define vsnwprintf vswprintf
+#endif
+
 TCOD_internal_context_t TCOD_ctx={
 	/* number of characters in the bitmap font */
 	16,16,
@@ -1591,6 +1595,7 @@ void detectBigEndianness(){
 	}
 }
 
+#if !defined(__NetBSD__)
 uint16 bswap16(uint16 s){
 	uint8* ps = (uint8*)&s;
 	uint16 res;
@@ -1610,6 +1615,7 @@ uint32 bswap32(uint32 s){
 	pres[3]=ps[0];
 	return res;
 }
+#endif
 
 uint16 l16(uint16 s){
 	if (isBigEndian) return bswap16(s); else return s;
