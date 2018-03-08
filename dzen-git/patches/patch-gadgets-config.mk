$NetBSD$

Adapt gadgets/config.mk to pkgsrc

--- gadgets/config.mk	2013-09-23 09:57:39.000000000 +0000
+++ gadgets-config.mk
@@ -1,18 +1,16 @@
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+MANPREFIX = ${PREFIX}/${PKGMANDIR}
 
-X11INC = /usr/X11R6/include
+X11INC = ${X11BASE}include
 INCS = -I. -I/usr/include -I${X11INC}
 
-X11LIB = /usr/X11R6/lib
-LIBS = -L/usr/lib 
+X11LIB = ${X11BASE}/lib
+LIBS = -lc
 
-CFLAGS = -Os ${INCS} 
-LDFLAGS = ${LIBS}
+CFLAGS = ${INCS} 
+LDFLAGS += ${LIBS}
 
 # compiler and linker
-CC = gcc
 LD = ${CC}
