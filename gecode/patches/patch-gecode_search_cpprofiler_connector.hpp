$NetBSD$

Add header for send(2).

--- gecode/search/cpprofiler/connector.hpp.orig	2025-09-14 22:44:02.789003303 +0000
+++ gecode/search/cpprofiler/connector.hpp
@@ -57,6 +57,7 @@ typedef SSIZE_T ssize_t;
 
 #include <netdb.h>
 #include <unistd.h>
+#include <sys/socket.h>
 
 #endif
 
