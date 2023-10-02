$NetBSD$

--- emulation/tools/socket.cpp.orig	2023-04-21 20:52:47.000000000 +0000
+++ emulation/tools/socket.cpp
@@ -5,6 +5,7 @@
 #else
     #define closesocket close
     #include <sys/socket.h>
+    #include <sys/time.h>
     #include <netdb.h>
     #include <netinet/in.h>
     #include <netinet/tcp.h>
