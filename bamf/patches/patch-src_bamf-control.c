$NetBSD$

--- src/bamf-control.c.orig	2020-08-21 17:04:33.301925635 +0000
+++ src/bamf-control.c
@@ -26,9 +26,6 @@
 #include "bamf-daemon.h"
 #include "bamf-matcher.h"
 
-G_DEFINE_TYPE (BamfControl, bamf_control, BAMF_DBUS_TYPE_CONTROL_SKELETON);
-#define BAMF_CONTROL_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE(obj, \
-BAMF_TYPE_CONTROL, BamfControlPrivate))
 
 struct _BamfControlPrivate
 {
@@ -37,6 +34,8 @@ struct _BamfControlPrivate
   GList *sources;
 };
 
+G_DEFINE_TYPE_WITH_PRIVATE (BamfControl, bamf_control, BAMF_DBUS_TYPE_CONTROL_SKELETON);
+
 static void
 bamf_control_on_launched_callback (GDBusConnection *connection,
                                    const gchar *sender_name,
@@ -147,7 +146,7 @@ on_dbus_handle_create_local_desktop_file
 static void
 bamf_control_init (BamfControl * self)
 {
-  self->priv = BAMF_CONTROL_GET_PRIVATE (self);
+  self->priv = bamf_control_get_instance_private (self);
   self->priv->sources = NULL;
 
   /* Registering signal callbacks to reply to dbus method calls */
@@ -194,7 +193,6 @@ bamf_control_class_init (BamfControlClas
   obj_class->constructed = bamf_control_constructed;
   obj_class->finalize = bamf_control_finalize;
 
-  g_type_class_add_private (klass, sizeof (BamfControlPrivate));
 }
 
 void
