$NetBSD: patch-unix-serchan.cxx,v 1.2 2012/12/01 15:28:03 darcy Exp $

- Add Dragonfly support

--- src/ptlib/unix/serchan.cxx.orig	2009-09-21 00:25:17.000000000 +0000
+++ src/ptlib/unix/serchan.cxx
@@ -43,7 +43,7 @@
 #define  TCSETATTR(f,t)  tcsetattr(f,TCSANOW,t)
 #define  TCGETATTR(f,t)  tcgetattr(f,t)
 
-#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined (P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_RTEMS)
+#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined (P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_RTEMS) || defined(P_DRAGONFLY)
 #include <sys/ttycom.h>
 #define TCGETA TIOCGETA
 #define TCSETAW TIOCSETAW
