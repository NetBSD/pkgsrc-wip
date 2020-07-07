$NetBSD$

--- src/libthread/sysofiles.sh.orig	2020-06-22 15:22:27.000000000 +0000
+++ src/libthread/sysofiles.sh
@@ -3,9 +3,6 @@
 test -f $PLAN9/config && . $PLAN9/config
 
 case "$SYSNAME" in
-NetBSD)
-	echo ${SYSNAME}-${OBJTYPE}-asm.o $SYSNAME.o stkmalloc.o
-	;;
 OpenBSD)
 	echo pthread.o stkmmap.o
 	;;
