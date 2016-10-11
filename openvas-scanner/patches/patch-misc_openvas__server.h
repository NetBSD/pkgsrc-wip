$NetBSD$

--- misc/openvas_server.h.orig	2015-08-03 10:14:29.000000000 +0000
+++ misc/openvas_server.h
@@ -48,6 +48,10 @@ extern "C"
 #ifdef _WIN32
 #include <winsock2.h>
 #else
+#if defined(__NetBSD__)
+#include <netinet/in_systm.h>
+#include <netinet/in.h>
+#endif
 #include <netinet/ip.h>
 #endif
 
