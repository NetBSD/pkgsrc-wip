$NetBSD$

Do not hardcode system paths. This is pkgsrc-specific.

--- incron.h.orig	2023-02-03 02:00:21.341596994 +0000
+++ incron.h
@@ -33,7 +33,7 @@
 #define INCRON_BUG_ADDRESS "<bugs@aiken.cz>"
 
 /// Default configuration file
-#define INCRON_CONFIG "/etc/incron.conf"
+#define INCRON_CONFIG "@PKG_SYSCONFBASE@/incron.conf"
 
 
 #endif //_INCRON_H_
