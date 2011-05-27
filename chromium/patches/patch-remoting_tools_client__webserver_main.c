$NetBSD: patch-remoting_tools_client__webserver_main.c,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- remoting/tools/client_webserver/main.c.orig	2011-05-24 08:01:04.000000000 +0000
+++ remoting/tools/client_webserver/main.c
@@ -21,6 +21,8 @@
 #include <netinet/in.h>
 
 #if defined (OS_POSIX)
+#include <signal.h>
+#include <sys/socket.h>
 #include <unistd.h>
 #endif //  OS_POSIX
 
