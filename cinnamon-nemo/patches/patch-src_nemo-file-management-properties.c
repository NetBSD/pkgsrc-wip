$NetBSD$

--- src/nemo-file-management-properties.c.orig	2016-06-23 12:33:15.000000000 +0000
+++ src/nemo-file-management-properties.c
@@ -40,6 +40,10 @@
 #include <libnemo-private/nemo-global-preferences.h>
 #include <libnemo-private/nemo-module.h>
 
+GSettings *gnome_media_handling_preferences;
+GSettings *nemo_list_view_preferences;
+GSettings *nemo_tree_sidebar_preferences;
+
 /* string enum preferences */
 #define NEMO_FILE_MANAGEMENT_PROPERTIES_DEFAULT_VIEW_WIDGET "default_view_combobox"
 #define NEMO_FILE_MANAGEMENT_PROPERTIES_ICON_VIEW_ZOOM_WIDGET "icon_view_zoom_combobox"
