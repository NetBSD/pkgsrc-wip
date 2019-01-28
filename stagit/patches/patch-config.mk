$NetBSD$

Do not overwrite LDFLAGS, so rpath is set correctly.

--- config.mk.orig	2018-04-08 12:24:12.000000000 +0000
+++ config.mk
@@ -20,7 +20,7 @@ LIBS = -L${GITLIB} -lgit2
 
 # optimized
 CFLAGS = -O2 -std=c99 ${INCS}
-LDFLAGS = -s ${LIBS}
+LDFLAGS += -s ${LIBS}
 
 # optimized static
 #CFLAGS = -static -O2 -std=c99 ${INCS}
