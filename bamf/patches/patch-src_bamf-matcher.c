$NetBSD$

--- src/bamf-matcher.c.orig	2020-08-21 17:17:52.997412942 +0000
+++ src/bamf-matcher.c
@@ -33,9 +33,7 @@
 #define EXEC_DESKTOP_FILE_OVERRIDE "--desktop_file_hint"
 #define ENV_DESKTOP_FILE_OVERRIDE "BAMF_DESKTOP_FILE_HINT"
 
-G_DEFINE_TYPE (BamfMatcher, bamf_matcher, BAMF_DBUS_TYPE_MATCHER_SKELETON);
-#define BAMF_MATCHER_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE(obj, \
-                                       BAMF_TYPE_MATCHER, BamfMatcherPrivate))
+G_DEFINE_TYPE_WITH_PRIVATE (BamfMatcher, bamf_matcher, BAMF_DBUS_TYPE_MATCHER_SKELETON);
 
 enum
 {
@@ -3111,7 +3109,7 @@ bamf_matcher_init (BamfMatcher * self)
   BamfLegacyScreen *screen;
   int i;
 
-  priv = self->priv = BAMF_MATCHER_GET_PRIVATE (self);
+  priv = self->priv = bamf_matcher_get_instance_private (self);
 
   priv->bad_prefixes = g_array_sized_new (FALSE, TRUE, sizeof (GRegex *),
                                           G_N_ELEMENTS (EXEC_BAD_PREFIXES));
@@ -3274,7 +3272,6 @@ bamf_matcher_class_init (BamfMatcherClas
 {
   GObjectClass *object_class = G_OBJECT_CLASS (klass);
 
-  g_type_class_add_private (klass, sizeof (BamfMatcherPrivate));
   object_class->dispose = bamf_matcher_dispose;
   object_class->finalize = bamf_matcher_finalize;
 
