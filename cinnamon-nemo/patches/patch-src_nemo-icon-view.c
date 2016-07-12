$NetBSD$

--- src/nemo-icon-view.c.orig	2016-06-23 12:33:15.000000000 +0000
+++ src/nemo-icon-view.c
@@ -69,6 +69,8 @@
 #include <sys/wait.h>
 #include <unistd.h>
 
+GSettings *nemo_compact_view_preferences;
+
 #define POPUP_PATH_ICON_APPEARANCE		"/selection/Icon Appearance Items"
 
 enum 
