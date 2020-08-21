$NetBSD$

--- src/bamf-application.c.orig	2020-08-21 14:00:31.952964663 +0000
+++ src/bamf-application.c
@@ -27,13 +27,9 @@
 #include <string.h>
 #include <gio/gdesktopappinfo.h>
 
-#define BAMF_APPLICATION_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE(obj, \
-BAMF_TYPE_APPLICATION, BamfApplicationPrivate))
 
 static void bamf_application_dbus_application_iface_init (BamfDBusItemApplicationIface *iface);
-G_DEFINE_TYPE_WITH_CODE (BamfApplication, bamf_application, BAMF_TYPE_VIEW,
-                         G_IMPLEMENT_INTERFACE (BAMF_DBUS_ITEM_TYPE_APPLICATION,
-                                                bamf_application_dbus_application_iface_init));
+
 
 struct _BamfApplicationPrivate
 {
@@ -48,6 +44,11 @@ struct _BamfApplicationPrivate
   gboolean show_stubs;
 };
 
+G_DEFINE_TYPE_WITH_CODE (BamfApplication, bamf_application, BAMF_TYPE_VIEW,
+			G_ADD_PRIVATE(BamfApplication)
+			G_IMPLEMENT_INTERFACE (BAMF_DBUS_ITEM_TYPE_APPLICATION,
+			bamf_application_dbus_application_iface_init));
+
 enum
 {
   SUPPORTED_MIMES_CHANGED,
@@ -1377,7 +1378,7 @@ static void
 bamf_application_init (BamfApplication * self)
 {
   BamfApplicationPrivate *priv;
-  priv = self->priv = BAMF_APPLICATION_GET_PRIVATE (self);
+  priv = self->priv = bamf_application_get_instance_private (self);
 
   priv->app_type = BAMF_APPLICATION_SYSTEM;
   priv->show_stubs = TRUE;
@@ -1447,7 +1448,7 @@ bamf_application_class_init (BamfApplica
   klass->get_close_when_empty = bamf_application_default_get_close_when_empty;
   klass->supported_mimes_changed = bamf_application_supported_mime_types_changed;
 
-  g_type_class_add_private (klass, sizeof (BamfApplicationPrivate));
+
 
   application_signals[SUPPORTED_MIMES_CHANGED] =
     g_signal_new ("supported-mimes-changed",
