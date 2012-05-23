$NetBSD: patch-config.h,v 1.1.1.1 2012/05/23 15:37:12 hfath Exp $

--- config.h.orig	2012-05-23 13:52:36.000000000 +0000
+++ config.h
@@ -59,6 +59,8 @@ enum config_enum {
 	CONFIG_AUTH_MODE,
 	CONFIG_CA_FILE,
 	CONFIG_CA_DIR,
+	CONFIG_DNS_UPDATE,
+	CONFIG_TARGET_NETWORKS,
 	LAST_CONFIG
 };
 
