$NetBSD$

--- src/nemo-action-config-widget.c.orig	2016-06-23 12:33:15.000000000 +0000
+++ src/nemo-action-config-widget.c
@@ -16,6 +16,7 @@
 
 G_DEFINE_TYPE (NemoActionConfigWidget, nemo_action_config_widget, NEMO_TYPE_CONFIG_BASE_WIDGET);
 
+GSettings *nemo_plugin_preferences;
 
 typedef struct {
     NemoActionConfigWidget *widget;
