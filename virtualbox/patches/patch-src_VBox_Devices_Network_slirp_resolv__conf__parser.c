$NetBSD$

--- src/VBox/Devices/Network/slirp/resolv_conf_parser.c.orig	2016-03-04 19:27:59.000000000 +0000
+++ src/VBox/Devices/Network/slirp/resolv_conf_parser.c
@@ -22,7 +22,7 @@
 #include <iprt/stream.h>
 #include <iprt/thread.h>
 
-#ifdef RT_OS_FREEBSD
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <sys/socket.h>
 #endif
 
