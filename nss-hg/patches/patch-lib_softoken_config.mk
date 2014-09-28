$NetBSD: patch-lib_softoken_config.mk,v 1.1 2014/09/28 14:20:09 thomasklausner Exp $

--- lib/softoken/config.mk.orig	2014-09-28 13:54:02.000000000 +0000
+++ lib/softoken/config.mk
@@ -48,7 +48,7 @@ else
 # $(EXTRA_SHARED_LIBS) come before $(OS_LIBS), except on AIX.
 EXTRA_SHARED_LIBS += \
 	-L$(DIST)/lib \
-	-l$(SQLITE_LIB_NAME) \
+	`pkg-config --libs sqlite3` \
 	-L$(NSSUTIL_LIB_DIR) \
 	-lnssutil3 \
 	-L$(NSPR_LIB_DIR) \
