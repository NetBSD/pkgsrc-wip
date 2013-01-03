$NetBSD: patch-lib_irrlicht_source_Irrlicht_os.cpp,v 1.1 2013/01/03 13:03:30 ryo-on Exp $

--- lib/irrlicht/source/Irrlicht/os.cpp.orig	2013-01-03 12:37:18.000000000 +0000
+++ lib/irrlicht/source/Irrlicht/os.cpp
@@ -22,7 +22,7 @@
 	#include <libkern/OSByteOrder.h>
 	#define bswap_16(X) OSReadSwapInt16(&X,0)
 	#define bswap_32(X) OSReadSwapInt32(&X,0)
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 	#include <sys/endian.h>
 	#define bswap_16(X) bswap16(X)
 	#define bswap_32(X) bswap32(X)
