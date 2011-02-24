$NetBSD: patch-source_Irrlicht_os.cpp,v 1.1.1.1 2011/02/24 15:12:08 pallegra Exp $

--- source/Irrlicht/os.cpp.orig	2010-10-24 09:42:48.000000000 +0000
+++ source/Irrlicht/os.cpp
@@ -19,7 +19,7 @@
 	#include <libkern/OSByteOrder.h>
 	#define bswap_16(X) OSReadSwapInt16(&X,0)
 	#define bswap_32(X) OSReadSwapInt32(&X,0)
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 	#include <sys/endian.h>
 	#define bswap_16(X) bswap16(X)
 	#define bswap_32(X) bswap32(X)
