$NetBSD: patch-src_firmware.cpp,v 1.1 2012/04/20 08:13:24 othyro Exp $

Relocated patch for src/NDSSystem.cpp to here. Source file changed.

--- src/firmware.cpp.orig	2011-01-27 10:27:00.000000000 +0000
+++ src/firmware.cpp
@@ -74,7 +74,9 @@ void CFIRMWARE::crypt64BitDown(u32 *ptr)
 	ptr[1] = (Y ^ keyBuf[DWNUM(0x00)]);
 }
 
+#ifndef bswap32
 #define bswap32(val) (((val & 0x000000FF) << 24) | ((val & 0x0000FF00) << 8) | ((val & 0x00FF0000) >> 8) | ((val & 0xFF000000) >> 24))
+#endif
 void CFIRMWARE::applyKeycode(u32 modulo)
 {
 	crypt64BitUp(&keyCode[1]);
