$NetBSD$
Already Upstream
Use the OS function for endianess conversion
--- lib/irrlicht/source/Irrlicht/os.cpp.orig	2016-12-11 21:49:49.295840720 +0000
+++ lib/irrlicht/source/Irrlicht/os.cpp	2016-12-11 21:51:47.894076206 +0000
@@ -22,7 +22,7 @@
 	#include <libkern/OSByteOrder.h>
 	#define bswap_16(X) OSReadSwapInt16(&X,0)
 	#define bswap_32(X) OSReadSwapInt32(&X,0)
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 	#include <sys/endian.h>
 	#define bswap_16(X) bswap16(X)
 	#define bswap_32(X) bswap32(X)
