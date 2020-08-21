$NetBSD$

--- src/bamf-daemon.c.orig	2020-08-21 17:07:26.617706808 +0000
+++ src/bamf-daemon.c
@@ -21,10 +21,6 @@
 #include "bamf-matcher.h"
 #include "bamf-control.h"
 
-G_DEFINE_TYPE (BamfDaemon, bamf_daemon, G_TYPE_OBJECT);
-#define BAMF_DAEMON_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE(obj, \
-                                      BAMF_TYPE_DAEMON, BamfDaemonPrivate))
-
 static BamfDaemon *instance = NULL;
 
 struct _BamfDaemonPrivate
@@ -34,6 +30,8 @@ struct _BamfDaemonPrivate
   GMainLoop *loop;
 };
 
+G_DEFINE_TYPE_WITH_PRIVATE (BamfDaemon, bamf_daemon, G_TYPE_OBJECT);
+
 gboolean
 bamf_daemon_is_running (BamfDaemon *self)
 {
@@ -165,7 +163,7 @@ static void
 bamf_daemon_init (BamfDaemon *self)
 {
   BamfDaemonPrivate *priv;
-  priv = self->priv = BAMF_DAEMON_GET_PRIVATE (self);
+  priv = self->priv = bamf_daemon_get_instance_private (self);
 
   priv->loop = g_main_loop_new (NULL, FALSE);
 }
@@ -178,7 +176,6 @@ bamf_daemon_class_init (BamfDaemonClass 
   object_class->dispose  = bamf_daemon_dispose;
   object_class->finalize = bamf_daemon_finalize;
 
-  g_type_class_add_private (klass, sizeof (BamfDaemonPrivate));
 }
 
 BamfDaemon *
