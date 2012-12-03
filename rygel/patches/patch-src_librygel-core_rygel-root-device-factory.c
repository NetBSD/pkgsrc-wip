$NetBSD: patch-src_librygel-core_rygel-root-device-factory.c,v 1.1 2012/12/03 20:51:43 thomasklausner Exp $

Use BSD uuid functions instead of Linux ones.

--- src/librygel-core/rygel-root-device-factory.c.orig	2012-11-13 14:25:52.000000000 +0000
+++ src/librygel-core/rygel-root-device-factory.c
@@ -40,7 +40,7 @@
 #include <glib/gi18n-lib.h>
 #include <libgssdp/gssdp.h>
 #include <gio/gio.h>
-#include <uuid/uuid.h>
+#include <uuid.h>
 #include <gobject/gvaluecollector.h>
 
 
@@ -1612,6 +1612,7 @@ static gchar* rygel_root_device_factory_
 	gint id_length1;
 	gint _id_size_;
 	gchar* _tmp2_;
+	uint32_t status;
 	g_return_val_if_fail (self != NULL, NULL);
 	_tmp0_ = g_new0 (guchar, 50);
 	udn = _tmp0_;
@@ -1621,8 +1622,8 @@ static gchar* rygel_root_device_factory_
 	id = _tmp1_;
 	id_length1 = 16;
 	_id_size_ = id_length1;
-	uuid_generate (id);
-	uuid_unparse (id, udn);
+	uuid_create(id, &status);
+	uuid_to_string (id, &udn, &status);
 	_tmp2_ = g_strconcat ("uuid:", (const gchar*) udn, NULL);
 	result = _tmp2_;
 	id = (g_free (id), NULL);
