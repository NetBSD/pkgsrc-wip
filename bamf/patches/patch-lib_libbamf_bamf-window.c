$NetBSD$

--- lib/libbamf/bamf-window.c.orig	2020-08-21 13:57:00.460655597 +0000
+++ lib/libbamf/bamf-window.c
@@ -40,11 +40,6 @@
 #include "bamf-window.h"
 #include "bamf-factory.h"
 
-G_DEFINE_TYPE (BamfWindow, bamf_window, BAMF_TYPE_VIEW);
-
-#define BAMF_WINDOW_GET_PRIVATE(o) \
-  (G_TYPE_INSTANCE_GET_PRIVATE ((o), BAMF_TYPE_WINDOW, BamfWindowPrivate))
-
 struct _BamfWindowPrivate
 {
   BamfDBusItemWindow        *proxy;
@@ -56,6 +51,8 @@ struct _BamfWindowPrivate
   BamfWindowMaximizationType maximized;
 };
 
+G_DEFINE_TYPE_WITH_PRIVATE (BamfWindow, bamf_window, BAMF_TYPE_VIEW);
+
 enum
 {
   MONITOR_CHANGED,
@@ -412,7 +409,6 @@ bamf_window_class_init (BamfWindowClass 
   GObjectClass  *obj_class  = G_OBJECT_CLASS (klass);
   BamfViewClass *view_class = BAMF_VIEW_CLASS (klass);
 
-  g_type_class_add_private (obj_class, sizeof (BamfWindowPrivate));
 
   obj_class->dispose = bamf_window_dispose;
   view_class->active_changed = bamf_window_active_changed;
@@ -442,7 +438,7 @@ bamf_window_init (BamfWindow *self)
 {
   BamfWindowPrivate *priv;
 
-  priv = self->priv = BAMF_WINDOW_GET_PRIVATE (self);
+  priv = self->priv = bamf_window_get_instance_private (self);
   priv->xid = 0;
   priv->pid = 0;
   priv->type = BAMF_WINDOW_UNKNOWN;
