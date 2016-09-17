$NetBSD$

--- src/osdep/byteorder.h.orig	2016-02-14 23:34:57.000000000 +0000
+++ src/osdep/byteorder.h
@@ -224,7 +224,7 @@
 	#endif
 
 	// FreeBSD
-	#ifdef __FreeBSD__
+	#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 		#undef ushort
 		#undef uint
 		#include <sys/types.h>
