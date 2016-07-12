$NetBSD$

--- src/nemo-desktop-icon-view.c.orig	2016-06-23 12:33:15.000000000 +0000
+++ src/nemo-desktop-icon-view.c
@@ -61,6 +61,9 @@
 #include <sys/types.h>
 #include <unistd.h>
 
+GSettings *gnome_lockdown_preferences;
+GSettings *nemo_icon_view_preferences;
+
 /* Timeout to check the desktop directory for updates */
 #define RESCAN_TIMEOUT 4
 
