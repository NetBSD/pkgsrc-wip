$NetBSD$

--- lib/libbamf/bamf-view.c.orig	2020-08-21 13:54:16.025518785 +0000
+++ lib/libbamf/bamf-view.c
@@ -43,11 +43,6 @@
 #include "bamf-tab.h"
 #include "bamf-window.h"
 
-G_DEFINE_TYPE (BamfView, bamf_view, G_TYPE_INITIALLY_UNOWNED);
-
-#define BAMF_VIEW_GET_PRIVATE(o) \
-  (G_TYPE_INSTANCE_GET_PRIVATE ((o), BAMF_TYPE_VIEW, BamfViewPrivate))
-
 enum
 {
   ACTIVE_CHANGED,
@@ -93,6 +88,8 @@ struct _BamfViewPrivate
   gboolean          sticky;
 };
 
+G_DEFINE_TYPE_WITH_PRIVATE (BamfView, bamf_view, G_TYPE_INITIALLY_UNOWNED);
+
 static void bamf_view_unset_proxy (BamfView *self);
 
 /**
@@ -943,7 +940,6 @@ bamf_view_class_init (BamfViewClass *kla
   properties[PROP_USER_VISIBLE] = g_param_spec_boolean ("user-visible", "user-visible", "user-visible", FALSE, G_PARAM_READABLE);
   g_object_class_install_property (obj_class, PROP_USER_VISIBLE, properties[PROP_USER_VISIBLE]);
 
-  g_type_class_add_private (obj_class, sizeof (BamfViewPrivate));
 
   view_signals [ACTIVE_CHANGED] =
     g_signal_new (BAMF_VIEW_SIGNAL_ACTIVE_CHANGED,
@@ -1050,7 +1046,7 @@ bamf_view_init (BamfView *self)
 {
   BamfViewPrivate *priv;
 
-  priv = self->priv = BAMF_VIEW_GET_PRIVATE (self);
+  priv = self->priv = bamf_view_get_instance_private (self);
   priv->cancellable = g_cancellable_new ();
   priv->is_closed = TRUE;
   priv->reload_children = TRUE;
