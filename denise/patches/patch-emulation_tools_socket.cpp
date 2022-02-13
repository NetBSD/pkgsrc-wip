$NetBSD$

Include required header file.

--- emulation/tools/socket.cpp.orig	2021-05-12 15:32:16.000000000 +0000
+++ emulation/tools/socket.cpp
@@ -6,6 +6,7 @@
     #define closesocket close
     #include <sys/socket.h>
     #include <netdb.h>
+    #include <netinet/in.h>
     #include <netinet/tcp.h>
     #include <unistd.h>
     #include <cerrno>
