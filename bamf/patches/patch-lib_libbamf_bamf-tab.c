$NetBSD$

--- lib/libbamf/bamf-tab.c.orig	2020-08-21 13:51:19.813165873 +0000
+++ lib/libbamf/bamf-tab.c
@@ -29,8 +29,6 @@
 #include "bamf-tab.h"
 #include "bamf-view-private.h"
 
-#define BAMF_TAB_GET_PRIVATE(object) (G_TYPE_INSTANCE_GET_PRIVATE (object, BAMF_TYPE_TAB, BamfTabPrivate))
-
 enum
 {
   PROP_0,
@@ -47,7 +45,7 @@ struct _BamfTabPrivate
 
 static void bamf_tab_unset_proxy (BamfTab *self);
 
-G_DEFINE_TYPE (BamfTab, bamf_tab, BAMF_TYPE_VIEW);
+G_DEFINE_TYPE_WITH_PRIVATE (BamfTab, bamf_tab, BAMF_TYPE_VIEW);
 
 static void
 on_proxy_property_change (GObject *gobject, GParamSpec *pspec, gpointer user_data)
@@ -170,13 +168,12 @@ bamf_tab_class_init (BamfTabClass *klass
                                FALSE, G_PARAM_READABLE);
   g_object_class_install_property (obj_class, PROP_IS_FOREGROUND_TAB, pspec);
 
-  g_type_class_add_private (obj_class, sizeof(BamfTabPrivate));
 }
 
 static void
 bamf_tab_init (BamfTab *self)
 {
-  self->priv = BAMF_TAB_GET_PRIVATE (self);
+  self->priv = bamf_tab_get_instance_private (self);
 }
 
 BamfTab *
