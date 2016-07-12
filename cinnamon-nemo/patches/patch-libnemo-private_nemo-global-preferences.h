$NetBSD$

--- libnemo-private/nemo-global-preferences.h.orig	2016-06-23 12:33:15.000000000 +0000
+++ libnemo-private/nemo-global-preferences.h
@@ -259,21 +259,21 @@ gboolean nemo_global_preferences_get_ign
 gint nemo_global_preferences_get_tooltip_flags (void);
 gboolean nemo_global_preferences_should_load_plugin (const gchar *name, const gchar *key);
 
-GSettings *nemo_preferences;
-GSettings *nemo_icon_view_preferences;
-GSettings *nemo_list_view_preferences;
-GSettings *nemo_compact_view_preferences;
-GSettings *nemo_desktop_preferences;
-GSettings *nemo_tree_sidebar_preferences;
-GSettings *nemo_window_state;
-GSettings *nemo_plugin_preferences;
-GSettings *gnome_lockdown_preferences;
-GSettings *gnome_background_preferences;
-GSettings *gnome_media_handling_preferences;
-GSettings *gnome_terminal_preferences;
-GSettings *cinnamon_privacy_preferences;
+extern GSettings *nemo_preferences;
+extern GSettings *nemo_icon_view_preferences;
+extern GSettings *nemo_list_view_preferences;
+extern GSettings *nemo_compact_view_preferences;
+extern GSettings *nemo_desktop_preferences;
+extern GSettings *nemo_tree_sidebar_preferences;
+extern GSettings *nemo_window_state;
+extern GSettings *nemo_plugin_preferences;
+extern GSettings *gnome_lockdown_preferences;
+extern GSettings *gnome_background_preferences;
+extern GSettings *gnome_media_handling_preferences;
+extern GSettings *gnome_terminal_preferences;
+extern GSettings *cinnamon_privacy_preferences;
 
-gint64 nemo_startup_time;
+extern gint64 nemo_startup_time;
 
 G_END_DECLS
 
