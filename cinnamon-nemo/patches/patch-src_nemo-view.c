$NetBSD$

--- src/nemo-view.c.orig	2016-06-23 12:33:15.000000000 +0000
+++ src/nemo-view.c
@@ -92,6 +92,8 @@
 #include <libnemo-private/nemo-action-manager.h>
 #include <libnemo-private/nemo-mime-application-chooser.h>
 
+GSettings *gnome_terminal_preferences;
+
 #define DEBUG_FLAG NEMO_DEBUG_DIRECTORY_VIEW
 #include <libnemo-private/nemo-debug.h>
 
