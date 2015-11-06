$NetBSD$

--- 3rdparty/mongoose/mongoose.c.orig	2015-02-15 20:01:07.000000000 +0000
+++ 3rdparty/mongoose/mongoose.c
@@ -118,6 +118,13 @@ typedef struct _stati64 ns_stat_t;
 #include <netdb.h>
 #include <pthread.h>
 #include <stdarg.h>
+#ifndef va_copy
+#ifdef __va_copy
+#define va_copy(x,y) __va_copy((x), (y))
+#else
+#define va_copy(x,y) ((x) = (y))
+#endif // NetBSD defines va_copy only when certain conditions are met
+#endif
 #include <unistd.h>
 #include <arpa/inet.h>  // For inet_pton() when NS_ENABLE_IPV6 is defined
 #include <netinet/in.h>
