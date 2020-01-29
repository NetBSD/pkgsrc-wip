$NetBSD$
--- src/io/network.cpp.orig	2019-01-06 13:41:53.000000000 +0000
+++ src/io/network.cpp
@@ -63,6 +63,8 @@
 	#include <sys/select.h>
 #endif
 
+#include <sys/time.h>
+
 /**
  * Initialise networking.
  */
@@ -174,7 +176,7 @@ int Network::join (char *address) {
 #ifdef USE_SOCKETS
 	sockaddr_in sockAddr;
 	fd_set writefds;
-	timeval timeouttv;
+	struct timeval timeouttv;
 	unsigned int timeout;
 	int sock, con;
 
