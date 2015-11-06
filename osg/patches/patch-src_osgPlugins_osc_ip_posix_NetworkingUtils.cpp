$NetBSD$

ntohl(3) is defined in arpa/inet.h, not in netinet/in.h.

--- src/osgPlugins/osc/ip/posix/NetworkingUtils.cpp.orig	2013-02-04 12:50:51.000000000 +0000
+++ src/osgPlugins/osc/ip/posix/NetworkingUtils.cpp
@@ -29,8 +29,8 @@
 */
 #include "ip/NetworkingUtils.h"
 
+#include <arpa/inet.h>
 #include <netdb.h>
-#include <sys/socket.h>
 #include <netinet/in.h>
 #include <string.h>
 #include <stdio.h>
