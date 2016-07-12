$NetBSD$

--- src/nemo-application.c.orig	2016-06-23 12:33:15.000000000 +0000
+++ src/nemo-application.c
@@ -87,6 +87,11 @@
 
 #include <libcinnamon-desktop/gnome-desktop-thumbnail.h>
 
+GSettings *nemo_desktop_preferences;
+GSettings *nemo_preferences;
+gint64 nemo_startup_time;
+GSettings *nemo_window_state;
+
 /* Keep window from shrinking down ridiculously small; numbers are somewhat arbitrary */
 #define APPLICATION_WINDOW_MIN_WIDTH	300
 #define APPLICATION_WINDOW_MIN_HEIGHT	100
