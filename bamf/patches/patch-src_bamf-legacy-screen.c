$NetBSD$

--- src/bamf-legacy-screen.c.orig	2020-08-21 17:09:53.372707266 +0000
+++ src/bamf-legacy-screen.c
@@ -26,10 +26,6 @@
 #include <libsn/sn.h>
 #undef SN_API_NOT_YET_FROZEN
 
-G_DEFINE_TYPE (BamfLegacyScreen, bamf_legacy_screen, G_TYPE_OBJECT);
-#define BAMF_LEGACY_SCREEN_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE(obj, \
-BAMF_TYPE_LEGACY_SCREEN, BamfLegacyScreenPrivate))
-
 static BamfLegacyScreen *static_screen = NULL;
 
 enum
@@ -61,6 +57,8 @@ struct _BamfLegacyScreenPrivate
   GDataInputStream *stream;
 };
 
+G_DEFINE_TYPE_WITH_PRIVATE (BamfLegacyScreen, bamf_legacy_screen, G_TYPE_OBJECT);
+
 static void
 handle_window_closed (BamfLegacyWindow *window, BamfLegacyScreen *self)
 {
@@ -459,7 +457,7 @@ bamf_legacy_screen_finalize (GObject *ob
 static void
 bamf_legacy_screen_init (BamfLegacyScreen * self)
 {
-  self->priv = BAMF_LEGACY_SCREEN_GET_PRIVATE (self);
+  self->priv = bamf_legacy_screen_get_instance_private (self);
 }
 
 static void
@@ -469,8 +467,6 @@ bamf_legacy_screen_class_init (BamfLegac
 
   object_class->finalize = bamf_legacy_screen_finalize;
 
-  g_type_class_add_private (klass, sizeof (BamfLegacyScreenPrivate));
-
   legacy_screen_signals [WINDOW_OPENING] =
     g_signal_new (BAMF_LEGACY_SCREEN_SIGNAL_WINDOW_OPENING,
                   G_OBJECT_CLASS_TYPE (klass),
