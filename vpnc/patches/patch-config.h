$NetBSD: patch-config.h,v 1.2 2014/02/20 20:53:59 hfath Exp $

--- config.h.orig	2014-09-05 20:53:13.000000000 +0000
+++ config.h
@@ -60,6 +60,8 @@ enum config_enum {
 	CONFIG_CA_FILE,
 	CONFIG_CA_DIR,
 	CONFIG_PASSWORD_HELPER,
+	CONFIG_DNS_UPDATE,
+	CONFIG_TARGET_NETWORKS,
 	LAST_CONFIG
 };
 
