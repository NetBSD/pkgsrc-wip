$NetBSD$

Fix clang build.

--- src/app-indicator.c.orig	2012-07-11 17:28:34.000000000 +0000
+++ src/app-indicator.c
@@ -196,9 +196,9 @@ static void bus_creation (GObject * obj,
 static void bus_watcher_ready (GObject * obj, GAsyncResult * res, gpointer user_data);
 
 static const GDBusInterfaceVTable item_interface_table = {
-	method_call:    bus_method_call,
-	get_property:   bus_get_prop,
-	set_property:   NULL /* No properties that can be set */
+	.method_call =    bus_method_call,
+	.get_property =   bus_get_prop,
+	.set_property =   NULL /* No properties that can be set */
 };
 
 /* GObject type */
