$NetBSD: patch-common_network_TcpSocket.cxx,v 1.1 2012/11/12 14:32:14 thomasklausner Exp $

atoi() prototype.

--- common/network/TcpSocket.cxx.orig	2006-05-15 16:56:20.000000000 +0000
+++ common/network/TcpSocket.cxx
@@ -33,6 +33,7 @@
 #include <unistd.h>
 #include <errno.h>
 #include <string.h>
+#include <stdlib.h>
 #include <signal.h>
 #include <fcntl.h>
 #endif
