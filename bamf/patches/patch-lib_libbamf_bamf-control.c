$NetBSD$

--- lib/libbamf/bamf-control.c.orig	2020-08-21 13:31:43.215667750 +0000
+++ lib/libbamf/bamf-control.c
@@ -39,16 +39,13 @@
 #include "bamf-control.h"
 #include "bamf-view-private.h"
 
-G_DEFINE_TYPE (BamfControl, bamf_control, G_TYPE_OBJECT);
-
-#define BAMF_CONTROL_GET_PRIVATE(o) \
-  (G_TYPE_INSTANCE_GET_PRIVATE ((o), BAMF_TYPE_CONTROL, BamfControlPrivate))
-
 struct _BamfControlPrivate
 {
   BamfDBusControl *proxy;
 };
 
+G_DEFINE_TYPE_WITH_PRIVATE (BamfControl, bamf_control, G_TYPE_OBJECT);
+
 /* Globals */
 static BamfControl * default_control = NULL;
 
@@ -87,7 +84,6 @@ bamf_control_class_init (BamfControlClas
   obj_class->dispose = bamf_control_dispose;
   obj_class->finalize = bamf_control_finalize;
 
-  g_type_class_add_private (obj_class, sizeof (BamfControlPrivate));
   obj_class->dispose = bamf_control_dispose;
 }
 
@@ -97,7 +93,7 @@ bamf_control_init (BamfControl *self)
   BamfControlPrivate *priv;
   GError           *error = NULL;
 
-  priv = self->priv = BAMF_CONTROL_GET_PRIVATE (self);
+  priv = self->priv = bamf_control_get_instance_private (self);
 
   priv->proxy = _bamf_dbus_control_proxy_new_for_bus_sync (G_BUS_TYPE_SESSION,
                                                            G_DBUS_PROXY_FLAGS_NONE,
