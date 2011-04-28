$NetBSD: patch-remoting_tools_client__webserver_main.c,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- remoting/tools/client_webserver/main.c.orig	2011-04-13 08:01:07.000000000 +0000
+++ remoting/tools/client_webserver/main.c
@@ -21,6 +21,7 @@
 #include <netinet/in.h>
 
 #if defined (OS_POSIX)
+#include <signal.h>
 #include <unistd.h>
 #endif //  OS_POSIX
 
