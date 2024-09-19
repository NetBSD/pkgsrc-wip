$NetBSD$

Adapt config.mk to pkgsrc.

--- config.mk	2013-09-23 09:57:39.000000000 +0000
+++ config.mk
@@ -4,11 +4,10 @@ VERSION = 0.9.5-svn
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+MANPREFIX = ${PREFIX}/${PKGMANDIR}
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC = ${X11BASE}/include
+X11LIB = ${X11BASE}/lib
 INCS = -I. -I/usr/include -I${X11INC}
 
 # Configure the features you want to be supported
@@ -19,8 +18,8 @@ INCS = -I. -I/usr/include -I${X11INC}
 # Comment  : Add # to the beginning of the respective lines
 
 ## Option 1: No Xinerama no XPM no XFT
-#LIBS = -L/usr/lib -lc -L${X11LIB} -lX11
-#CFLAGS = -Wall -Os ${INCS} -DVERSION=\"${VERSION}\"
+LIBS = -lc -L${X11LIB} -lX11
+CFLAGS = -Wall ${INCS} -DVERSION=\"${VERSION}\"
 
 
 ## Option 2: No Xinerama with XPM
@@ -39,8 +38,8 @@ INCS = -I. -I/usr/include -I${X11INC}
 
 
 ## Option 5: With XFT
-LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 `pkg-config --libs xft`
-CFLAGS = -Wall -Os ${INCS} -DVERSION=\"${VERSION}\" -DDZEN_XFT `pkg-config --cflags xft`
+#LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 `pkg-config --libs xft`
+#CFLAGS = -Wall -Os ${INCS} -DVERSION=\"${VERSION}\" -DDZEN_XFT `pkg-config --cflags xft`
 
 
 ## Option 6: With XPM and XFT
@@ -62,7 +61,7 @@ CFLAGS = -Wall -Os ${INCS} -DVERSION=\"$
 # END of feature configuration
 
 
-LDFLAGS = ${LIBS}
+LDFLAGS += ${LIBS}
 
 # Solaris, uncomment for Solaris
 #CFLAGS = -fast ${INCS} -DVERSION=\"${VERSION}\"
@@ -74,5 +73,5 @@ LDFLAGS = ${LIBS}
 #LDFLAGS = ${LIBS}
 
 # compiler and linker
-CC = gcc
+#CC = gcc
 LD = ${CC}
