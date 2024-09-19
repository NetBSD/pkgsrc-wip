$NetBSD$
Missing header causes compile error.
--- server/http-server.c.orig	2017-01-14 11:07:22.083948169 +0000
+++ server/http-server.c	2017-01-14 11:04:38.229103279 +0000
@@ -12,6 +12,10 @@
 #include <event.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <resolv.h>
+#endif
+
 #include <evhtp.h>
 
 #include "utils.h"
