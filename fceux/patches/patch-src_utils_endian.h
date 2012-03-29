$NetBSD: patch-src_utils_endian.h,v 1.1 2012/03/29 21:28:22 thomasklausner Exp $

Fix build with clang-3.1.

--- src/utils/endian.h.orig	2010-11-07 23:33:11.000000000 +0000
+++ src/utils/endian.h
@@ -99,9 +99,9 @@ int writele(T *Bufo, EMUFILE*os)
 	CTASSERT(sizeof(T)==1||sizeof(T)==2||sizeof(T)==4||sizeof(T)==8);
 	switch(sizeof(T)) {
 		case 1: return write8le((uint8*)Bufo,os);
-		case 2: return write16le((uint16*)Bufo,os);
-		case 4: return write32le((uint32*)Bufo,os);
-		case 8: return write64le((uint64*)Bufo,os);
+		case 2: return write16le(*(uint16*)Bufo,os);
+		case 4: return write32le(*(uint32*)Bufo,os);
+		case 8: return write64le(*(uint64*)Bufo,os);
 		default:
 			return 0;
 	}
