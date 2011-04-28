$NetBSD: patch-ipc_ipc__channel__posix.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- ipc/ipc_channel_posix.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ ipc/ipc_channel_posix.cc
@@ -10,6 +10,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
+#include <sys/uio.h>
 #include <sys/un.h>
 
 #include <string>
