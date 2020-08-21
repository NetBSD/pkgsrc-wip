$NetBSD$

--- lib/libbamf/bamf-application.c.orig	2020-08-21 13:27:42.363343437 +0000
+++ lib/libbamf/bamf-application.c
@@ -45,10 +45,6 @@
 #include <gio/gdesktopappinfo.h>
 #include <string.h>
 
-G_DEFINE_TYPE (BamfApplication, bamf_application, BAMF_TYPE_VIEW);
-
-#define BAMF_APPLICATION_GET_PRIVATE(o) \
-  (G_TYPE_INSTANCE_GET_PRIVATE ((o), BAMF_TYPE_APPLICATION, BamfApplicationPrivate))
 
 enum
 {
@@ -71,6 +67,7 @@ struct _BamfApplicationPrivate
   int                      show_stubs;
 };
 
+G_DEFINE_TYPE_WITH_PRIVATE (BamfApplication, bamf_application, BAMF_TYPE_VIEW);
 /**
  * bamf_application_get_supported_mime_types:
  * @application: a #BamfApplication
@@ -711,7 +708,6 @@ bamf_application_class_init (BamfApplica
   view_class->set_sticky = bamf_application_set_sticky;
   view_class->click_behavior = bamf_application_get_click_suggestion;
 
-  g_type_class_add_private (obj_class, sizeof (BamfApplicationPrivate));
 
   application_signals [DESKTOP_FILE_UPDATED] =
     g_signal_new (BAMF_APPLICATION_SIGNAL_DESKTOP_FILE_UPDATED,
@@ -743,7 +739,7 @@ bamf_application_init (BamfApplication *
 {
   BamfApplicationPrivate *priv;
 
-  priv = self->priv = BAMF_APPLICATION_GET_PRIVATE (self);
+  priv = self->priv = bamf_application_get_instance_private (self);
   priv->show_stubs = -1;
 
   g_signal_connect (self, "child-added", G_CALLBACK (bamf_application_on_child_added), NULL);
