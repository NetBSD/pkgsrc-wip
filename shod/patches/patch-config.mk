$NetBSD$

Do not override user flags

--- config.mk.orig	2021-03-14 03:14:43.000000000 +0000
+++ config.mk
@@ -17,8 +17,8 @@ LIBS = -L${LOCALLIB} -L${X11LIB} -lX11 -
 
 # flags
 CPPFLAGS =
-CFLAGS = -Wall -Wextra ${INCS} ${CPPFLAGS}
-LDFLAGS = ${LIBS}
+CFLAGS += -Wall -Wextra ${INCS} ${CPPFLAGS}
+LDFLAGS += ${LIBS}
 
 # compiler and linker
 CC = cc
