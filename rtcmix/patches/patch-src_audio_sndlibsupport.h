$NetBSD$

--- src/audio/sndlibsupport.h.orig	2015-10-03 21:09:58.000000000 +0000
+++ src/audio/sndlibsupport.h
@@ -10,7 +10,7 @@
 #include <endian.h>      /* so that sndlib.h will get host byte-order right */
 #elif defined(MACOSX)
 #include <machine/endian.h>
-#elif defined(SGI)
+#elif defined(SGI) || defined(NETBSD)
 #include <sys/endian.h>
 #elif defined(FREEBSD)
 #include <machine/endian.h>
