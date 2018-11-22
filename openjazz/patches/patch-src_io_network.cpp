$NetBSD$
--- ./src/io/network.cpp.orig	2018-05-22 08:17:03.000000000 -0700
+++ ./src/io/network.cpp	2018-11-21 23:17:27.447313979 -0800
@@ -60,6 +60,7 @@
 	#include <arpa/inet.h>
 #endif
 
+#include <sys/time.h>
 
 /**
  * Initialise networking.
@@ -172,7 +173,7 @@
 #ifdef USE_SOCKETS
 	sockaddr_in sockAddr;
 	fd_set writefds;
-	timeval timeouttv;
+	struct timeval timeouttv;
 	unsigned int timeout;
 	int sock, con;
 
