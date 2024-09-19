$NetBSD$

--- src/bamf-tab.c.orig	2020-08-21 17:22:28.970915645 +0000
+++ src/bamf-tab.c
@@ -26,13 +26,7 @@
 
 #include "bamf-tab.h"
 
-#define BAMF_TAB_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE(obj, \
-BAMF_TYPE_TAB, BamfTabPrivate))
-
 static void bamf_tab_dbus_iface_init (BamfDBusItemTabIface *iface);
-G_DEFINE_ABSTRACT_TYPE_WITH_CODE (BamfTab, bamf_tab, BAMF_TYPE_VIEW,
-                                  G_IMPLEMENT_INTERFACE (BAMF_DBUS_ITEM_TYPE_TAB,
-                                                         bamf_tab_dbus_iface_init));
 
 enum
 {
@@ -48,6 +42,11 @@ struct _BamfTabPrivate
   BamfDBusItemTab *dbus_iface;
 };
 
+G_DEFINE_ABSTRACT_TYPE_WITH_CODE (BamfTab, bamf_tab, BAMF_TYPE_VIEW,
+				  G_ADD_PRIVATE(BamfTab)
+				  G_IMPLEMENT_INTERFACE (BAMF_DBUS_ITEM_TYPE_TAB,
+				  			 bamf_tab_dbus_iface_init));
+
 static const gchar *
 bamf_tab_get_view_type (BamfView *view)
 {
@@ -170,7 +169,7 @@ on_dbus_handle_request_preview (BamfDBus
 static void
 bamf_tab_init (BamfTab *self)
 {
-  self->priv = BAMF_TAB_GET_PRIVATE (self);
+  self->priv = bamf_tab_get_instance_private (self);
 
   self->priv->dbus_iface = _bamf_dbus_item_tab_skeleton_new ();
 
@@ -208,7 +207,6 @@ bamf_tab_class_init (BamfTabClass * klas
   g_object_class_override_property (object_class, PROP_XID, "xid");
   g_object_class_override_property (object_class, PROP_IS_FOREGROUND_TAB, "is-foreground-tab");
 
-  g_type_class_add_private (klass, sizeof (BamfTabPrivate));
 }
 
 
