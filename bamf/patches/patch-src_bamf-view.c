$NetBSD$

--- src/bamf-view.c.orig	2020-08-21 17:26:22.927143856 +0000
+++ src/bamf-view.c
@@ -20,13 +20,8 @@
 
 #include "bamf-view.h"
 
-#define BAMF_VIEW_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE(obj, \
-                                    BAMF_TYPE_VIEW, BamfViewPrivate))
 
 static void bamf_view_dbus_view_iface_init (BamfDBusItemViewIface *iface);
-G_DEFINE_TYPE_WITH_CODE (BamfView, bamf_view, BAMF_DBUS_ITEM_TYPE_OBJECT_SKELETON,
-                         G_IMPLEMENT_INTERFACE (BAMF_DBUS_ITEM_TYPE_VIEW,
-                                                bamf_view_dbus_view_iface_init));
 
 #define STARTING_MAX_WAIT 15
 
@@ -84,6 +79,11 @@ struct _BamfViewPrivate
   guint active_changed_idle;
 };
 
+G_DEFINE_TYPE_WITH_CODE (BamfView, bamf_view, BAMF_DBUS_ITEM_TYPE_OBJECT_SKELETON,
+                         G_ADD_PRIVATE(BamfView)
+                         G_IMPLEMENT_INTERFACE (BAMF_DBUS_ITEM_TYPE_VIEW,
+                                                bamf_view_dbus_view_iface_init));
+
 static gboolean
 on_active_changed_idle (gpointer data)
 {
@@ -964,7 +964,7 @@ bamf_view_set_property (GObject *object,
 static void
 bamf_view_init (BamfView * self)
 {
-  self->priv = BAMF_VIEW_GET_PRIVATE (self);
+  self->priv = bamf_view_get_instance_private (self);
 
   /* Initializing the dbus interface */
   self->priv->dbus_iface = _bamf_dbus_item_view_skeleton_new ();
@@ -1031,7 +1031,6 @@ bamf_view_class_init (BamfViewClass * kl
   object_class->get_property = bamf_view_get_property;
   object_class->set_property = bamf_view_set_property;
 
-  g_type_class_add_private (klass, sizeof (BamfViewPrivate));
 
   /* Overriding the properties defined in the interface, this is needed
    * but we actually don't use these properties, as we act like a proxy       */
