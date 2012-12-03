$NetBSD: patch-src_librygel-server_rygel-item-creator.c,v 1.1 2012/12/03 20:51:43 thomasklausner Exp $

Use BSD uuid functions instead of Linux ones.

--- src/librygel-server/rygel-item-creator.c.orig	2012-11-13 14:25:56.000000000 +0000
+++ src/librygel-server/rygel-item-creator.c
@@ -36,7 +36,7 @@
 #include <gst/gst.h>
 #include <libsoup/soup.h>
 #include <stdio.h>
-#include <uuid/uuid.h>
+#include <uuid.h>
 #include <libgupnp-dlna/gupnp-dlna-discoverer.h>
 #include <libgupnp-dlna/gupnp-dlna-profile.h>
 
@@ -2622,6 +2622,7 @@ static gchar* rygel_item_creator_mangle_
 	const gchar* _tmp18_;
 	gchar* _tmp19_;
 	gchar* _tmp20_;
+	int32_t status;
 	GError * _inner_error_ = NULL;
 	g_return_val_if_fail (self != NULL, NULL);
 	g_return_val_if_fail (title != NULL, NULL);
@@ -2653,12 +2654,12 @@ static gchar* rygel_item_creator_mangle_
 	_id_size_ = id_length1;
 	_tmp12_ = id;
 	_tmp12__length1 = id_length1;
-	uuid_generate (_tmp12_);
+	uuid_create (_tmp12_, &status);
 	_tmp13_ = id;
 	_tmp13__length1 = id_length1;
 	_tmp14_ = udn;
 	_tmp14__length1 = udn_length1;
-	uuid_unparse (_tmp13_, _tmp14_);
+	uuid_to_string (_tmp13_, &_tmp14_, &status);
 	_tmp15_ = udn;
 	_tmp15__length1 = udn_length1;
 	_tmp16_ = g_strconcat ((const gchar*) _tmp15_, "-", NULL);
