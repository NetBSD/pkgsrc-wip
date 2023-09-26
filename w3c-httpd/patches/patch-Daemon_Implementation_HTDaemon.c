$NetBSD$

Adjusted to the pkgsrc path.

--- Daemon/Implementation/HTDaemon.c.orig	1996-07-15 07:37:49.000000000 +0900
+++ Daemon/Implementation/HTDaemon.c	2023-09-27 01:42:30.288380200 +0900
@@ -97,7 +97,7 @@
 #ifdef VMS
 #define RULE_FILE               "httpd_dir:httpd.conf"
 #else /* not VMS */
-#define RULE_FILE               "/etc/httpd.conf"
+#define RULE_FILE               PREFIX "/etc/httpd.conf"
 #endif /* not VMS */
 #endif
 
