$NetBSD$

--- src/bamf-legacy-window.c.orig	2020-08-21 17:14:27.361957778 +0000
+++ src/bamf-legacy-window.c
@@ -29,10 +29,6 @@
 #include <glibtop/procuid.h>
 #include <stdio.h>
 
-G_DEFINE_TYPE (BamfLegacyWindow, bamf_legacy_window, G_TYPE_OBJECT);
-#define BAMF_LEGACY_WINDOW_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE(obj, \
-BAMF_TYPE_LEGACY_WINDOW, BamfLegacyWindowPrivate))
-
 #define WNCK_WINDOW_BAMF_DATA "bamf-legacy-window"
 
 enum
@@ -59,6 +55,8 @@ struct _BamfLegacyWindowPrivate
   gboolean     is_closed;
 };
 
+G_DEFINE_TYPE_WITH_PRIVATE (BamfLegacyWindow, bamf_legacy_window, G_TYPE_OBJECT);
+
 gboolean
 bamf_legacy_window_is_active (BamfLegacyWindow *self)
 {
@@ -704,7 +702,7 @@ bamf_legacy_window_dispose (GObject *obj
 static void
 bamf_legacy_window_init (BamfLegacyWindow * self)
 {
-  self->priv = BAMF_LEGACY_WINDOW_GET_PRIVATE (self);
+  self->priv = bamf_legacy_window_get_instance_private (self);
 
   g_signal_connect (wnck_screen_get_default (), "window-closed",
                     (GCallback) handle_window_closed, self);
@@ -717,8 +715,6 @@ bamf_legacy_window_class_init (BamfLegac
 
   object_class->dispose = bamf_legacy_window_dispose;
 
-  g_type_class_add_private (klass, sizeof (BamfLegacyWindowPrivate));
-
   legacy_window_signals [NAME_CHANGED] =
     g_signal_new (BAMF_LEGACY_WINDOW_SIGNAL_NAME_CHANGED,
                   G_OBJECT_CLASS_TYPE (klass),
