$NetBSD$
--- ./config.mk.orig	2016-01-06 09:48:12.000000000 -0800
+++ ./config.mk	2016-01-15 19:41:38.000000000 -0800
@@ -4,14 +4,13 @@
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/man
+MANPREFIX = ${PREFIX}/${PKGMANDIR}
 
-PNGLIB = /usr/local/lib
-PNGINC = /usr/local/include
+PNGLIB = ${PREFIX}/lib
+PNGINC = ${PREFIX}/include
 
-JPGLIB = /usr/local/lib
-JPGINC = /usr/local/include
+JPGLIB = ${PREFIX}/lib
+JPGINC = ${PREFIX}/include
 
 INCS = -I${PNGINC} -I${JPGINC}
 LIBS = -L${PNGLIB} -L${JPGLIB} -lpng -ljpeg
