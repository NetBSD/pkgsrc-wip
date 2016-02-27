$NetBSD$

--- lib/libwebsockets.h.orig	2016-02-25 02:11:01.000000000 +0000
+++ lib/libwebsockets.h
@@ -140,6 +140,10 @@ struct sockaddr_in;
 #else /* NOT WIN32 */
 #include <unistd.h>
 
+#if defined(__NetBSD__)
+#include <netinet/in.h>
+#endif
+
 #define LWS_INLINE inline
 #define LWS_O_RDONLY O_RDONLY
 
