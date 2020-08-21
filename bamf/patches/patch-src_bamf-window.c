$NetBSD$

--- src/bamf-window.c.orig	2020-08-21 17:30:11.363207557 +0000
+++ src/bamf-window.c
@@ -33,13 +33,7 @@
 #define _GTK_APPLICATION_ID "_GTK_APPLICATION_ID"
 #define SNAP_SECURITY_LABEL_PREFIX "snap."
 
-#define BAMF_WINDOW_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE(obj, \
-BAMF_TYPE_WINDOW, BamfWindowPrivate))
-
 static void bamf_window_dbus_iface_init (BamfDBusItemWindowIface *iface);
-G_DEFINE_TYPE_WITH_CODE (BamfWindow, bamf_window, BAMF_TYPE_VIEW,
-                         G_IMPLEMENT_INTERFACE (BAMF_DBUS_ITEM_TYPE_WINDOW,
-                                                bamf_window_dbus_iface_init));
 
 static GList *bamf_windows = NULL;
 
@@ -64,6 +58,11 @@ struct _BamfWindowPrivate
 #endif
 };
 
+G_DEFINE_TYPE_WITH_CODE (BamfWindow, bamf_window, BAMF_TYPE_VIEW,
+                         G_ADD_PRIVATE(BamfWindow)
+                         G_IMPLEMENT_INTERFACE (BAMF_DBUS_ITEM_TYPE_WINDOW,
+                                                bamf_window_dbus_iface_init));
+
 BamfLegacyWindow *
 bamf_window_get_window (BamfWindow *self)
 {
@@ -658,7 +657,7 @@ bamf_window_finalize (GObject *object)
 static void
 bamf_window_init (BamfWindow * self)
 {
-  self->priv = BAMF_WINDOW_GET_PRIVATE (self);
+  self->priv = bamf_window_get_instance_private (self);
 
   /* Initializing the dbus interface */
   self->priv->dbus_iface = _bamf_dbus_item_window_skeleton_new ();
@@ -726,7 +725,6 @@ bamf_window_class_init (BamfWindowClass 
                                G_PARAM_READWRITE | G_PARAM_CONSTRUCT);
   g_object_class_install_property (object_class, PROP_WINDOW, pspec);
 
-  g_type_class_add_private (klass, sizeof (BamfWindowPrivate));
 }
 
 BamfWindow *
