$NetBSD$

--- net/dns/dns_reloader.cc.orig	2016-06-24 01:02:25.000000000 +0000
+++ net/dns/dns_reloader.cc
@@ -5,7 +5,11 @@
 #include "net/dns/dns_reloader.h"
 
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
-    !defined(OS_ANDROID)
+    !defined(OS_ANDROID) && !defined(OS_NETBSD)
+
+#if defined(OS_FREEBSD)
+#include <netinet/in.h>
+#endif
 
 #include <resolv.h>
 
