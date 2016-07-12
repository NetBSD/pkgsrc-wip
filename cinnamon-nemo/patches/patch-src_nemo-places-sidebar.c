$NetBSD$

--- src/nemo-places-sidebar.c.orig	2016-07-12 16:40:07.000000000 +0000
+++ src/nemo-places-sidebar.c
@@ -61,6 +61,9 @@
 
 #include <libnotify/notify.h>
 
+GSettings *cinnamon_privacy_preferences;
+GSettings *gnome_background_preferences;
+
 #define DEBUG_FLAG NEMO_DEBUG_PLACES
 #include <libnemo-private/nemo-debug.h>
 
