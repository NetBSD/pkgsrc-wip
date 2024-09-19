$NetBSD: patch-daemon_spread__params.h,v 1.1 2013/10/18 10:16:13 fhajny Exp $

Fix default vars.
--- daemon/spread_params.h.orig	2013-06-12 03:51:25.000000000 +0000
+++ daemon/spread_params.h
@@ -46,13 +46,13 @@
 #define		DEFAULT_SPREAD_PORT	4803
 
 #ifndef SP_RUNTIME_DIR
-#define         SP_RUNTIME_DIR          "/var/run/spread"
+#define         SP_RUNTIME_DIR          "@SPREAD_DIR@"
 #endif
 #ifndef SP_GROUP
-#define         SP_GROUP                "spread"
+#define         SP_GROUP                "@SPREAD_GROUP@"
 #endif
 #ifndef SP_USER
-#define         SP_USER                 "spread"
+#define         SP_USER                 "@SPREAD_USER@"
 #endif
 #ifndef SP_UNIX_SOCKET
 #define         SP_UNIX_SOCKET          "/tmp"
