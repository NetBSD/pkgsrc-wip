$NetBSD: patch-lib_softoken_config.mk,v 1.3 2015/03/17 14:28:41 thomasklausner Exp $

Use pkg-config to find the proper sqlite3 (when not using the version
distributed with firefox - might not need upstreaming and stay as local
patch)

--- lib/softoken/config.mk.orig	2015-03-17 10:30:28.000000000 +0000
+++ lib/softoken/config.mk
@@ -48,7 +48,7 @@ else
 # $(EXTRA_SHARED_LIBS) come before $(OS_LIBS), except on AIX.
 EXTRA_SHARED_LIBS += \
 	-L$(SQLITE_LIB_DIR) \
-	-l$(SQLITE_LIB_NAME) \
+	`pkg-config --libs sqlite3` \
 	-L$(NSSUTIL_LIB_DIR) \
 	-lnssutil3 \
 	-L$(NSPR_LIB_DIR) \
