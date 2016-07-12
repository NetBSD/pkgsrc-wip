$NetBSD$

--- libnemo-private/nemo-global-preferences.c.orig	2016-06-23 12:33:15.000000000 +0000
+++ libnemo-private/nemo-global-preferences.c
@@ -36,6 +36,20 @@
 
 static gboolean ignore_view_metadata = FALSE;
 
+GSettings *cinnamon_privacy_preferences;
+GSettings *gnome_background_preferences;
+GSettings *gnome_lockdown_preferences;
+GSettings *gnome_media_handling_preferences;
+GSettings *gnome_terminal_preferences;
+GSettings *nemo_compact_view_preferences;
+GSettings *nemo_desktop_preferences;
+GSettings *nemo_icon_view_preferences;
+GSettings *nemo_list_view_preferences;
+GSettings *nemo_preferences;
+GSettings *nemo_tree_sidebar_preferences;
+GSettings *nemo_window_state;
+GSettings *nemo_plugin_preferences;
+
 /*
  * Public functions
  */
