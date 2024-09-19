$NetBSD$

--- src/wtmp-helper.h.orig	2019-04-23 15:16:09.000000000 +0000
+++ src/wtmp-helper.h
@@ -23,7 +23,9 @@
 
 #include <glib.h>
 #include <pwd.h>
+#ifdef HAVE_SHADOW_H
 #include <shadow.h>
+#endif
 
 const gchar *           wtmp_helper_get_path_for_monitor                (void);
 void                    wtmp_helper_update_login_frequencies            (GHashTable *users);
