$NetBSD$

--- lib/libbamf/bamf-matcher.c.orig	2020-08-21 13:42:08.090363505 +0000
+++ lib/libbamf/bamf-matcher.c
@@ -42,11 +42,6 @@
 #include "bamf-view-private.h"
 #include "bamf-factory.h"
 
-G_DEFINE_TYPE (BamfMatcher, bamf_matcher, G_TYPE_OBJECT);
-
-#define BAMF_MATCHER_GET_PRIVATE(o) \
-  (G_TYPE_INSTANCE_GET_PRIVATE ((o), BAMF_TYPE_MATCHER, BamfMatcherPrivate))
-
 enum
 {
   VIEW_OPENED,
@@ -68,6 +63,8 @@ struct _BamfMatcherPrivate
   BamfApplication *active_application;
 };
 
+G_DEFINE_TYPE_WITH_PRIVATE (BamfMatcher, bamf_matcher, G_TYPE_OBJECT);
+
 static BamfMatcher * default_matcher = NULL;
 
 static void bamf_matcher_dispose (GObject *object);
@@ -87,7 +84,6 @@ bamf_matcher_class_init (BamfMatcherClas
 {
   GObjectClass *obj_class = G_OBJECT_CLASS (klass);
 
-  g_type_class_add_private (obj_class, sizeof (BamfMatcherPrivate));
   obj_class->dispose = bamf_matcher_dispose;
   obj_class->finalize = bamf_matcher_finalize;
 
@@ -279,7 +275,7 @@ bamf_matcher_init (BamfMatcher *self)
   BamfMatcherPrivate *priv;
   GError *error = NULL;
 
-  priv = self->priv = BAMF_MATCHER_GET_PRIVATE (self);
+  priv = self->priv = bamf_matcher_get_instance_private (self);
   priv->cancellable = g_cancellable_new ();
   priv->proxy = _bamf_dbus_matcher_proxy_new_for_bus_sync (G_BUS_TYPE_SESSION,
                                                            G_DBUS_PROXY_FLAGS_NONE,
