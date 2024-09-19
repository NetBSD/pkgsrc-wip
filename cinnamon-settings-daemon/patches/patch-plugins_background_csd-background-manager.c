$NetBSD$

Fix with our accountsservice.

--- plugins/background/csd-background-manager.c.orig	2018-05-16 17:41:09.000000000 +0000
+++ plugins/background/csd-background-manager.c
@@ -136,7 +136,9 @@ settings_change_event_cb (GSettings     
         gnome_bg_load_from_preferences (manager->priv->bg,
                                         manager->priv->settings);
 
+#if ACCOUNTSERVICE_BG
         gnome_bg_set_accountsservice_background (gnome_bg_get_filename (manager->priv->bg));
+#endif
 
         return FALSE;
 }
@@ -187,7 +189,9 @@ setup_bg (CsdBackgroundManager *manager)
         gnome_bg_load_from_preferences (manager->priv->bg,
                                         manager->priv->settings);
 
+#if ACCOUNTSERVICE_BG
         gnome_bg_set_accountsservice_background (gnome_bg_get_filename (manager->priv->bg));
+#endif
 }
 
 static void
