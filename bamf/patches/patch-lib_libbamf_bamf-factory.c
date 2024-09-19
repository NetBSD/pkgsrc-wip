$NetBSD$

--- lib/libbamf/bamf-factory.c.orig	2020-08-21 13:35:11.363543004 +0000
+++ lib/libbamf/bamf-factory.c
@@ -40,17 +40,14 @@
 #include "bamf-application-private.h"
 #include "bamf-view-private.h"
 
-G_DEFINE_TYPE (BamfFactory, bamf_factory, G_TYPE_OBJECT);
-
-#define BAMF_FACTORY_GET_PRIVATE(o) \
-  (G_TYPE_INSTANCE_GET_PRIVATE ((o), BAMF_TYPE_FACTORY, BamfFactoryPrivate))
-
 struct _BamfFactoryPrivate
 {
   GHashTable *open_views;
   GList *allocated_views;
 };
 
+G_DEFINE_TYPE_WITH_PRIVATE (BamfFactory, bamf_factory, G_TYPE_OBJECT);
+
 static BamfFactory *static_factory = NULL;
 
 static void on_view_weak_unref (BamfFactory *self, BamfView *view_was_here);
@@ -108,14 +105,13 @@ bamf_factory_class_init (BamfFactoryClas
   obj_class->dispose = bamf_factory_dispose;
   obj_class->finalize = bamf_factory_finalize;
 
-  g_type_class_add_private (obj_class, sizeof (BamfFactoryPrivate));
 }
 
 
 static void
 bamf_factory_init (BamfFactory *self)
 {
-  self->priv = BAMF_FACTORY_GET_PRIVATE (self);
+  self->priv = bamf_factory_get_instance_private (self);
   self->priv->open_views = g_hash_table_new_full (g_str_hash, g_str_equal,
                                                   g_free, g_object_unref);
 }
