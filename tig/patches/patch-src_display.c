$NetBSD$

Rename boolean `refresh' to `brefresh' to avoid confusion with curses(3)
refresh().

--- src/display.c.orig	2017-09-29 15:15:26.000000000 +0000
+++ src/display.c
@@ -56,7 +56,7 @@ open_script(const char *path)
 }
 
 bool
-open_external_viewer(const char *argv[], const char *dir, bool silent, bool confirm, bool echo, bool refresh, const char *notice)
+open_external_viewer(const char *argv[], const char *dir, bool silent, bool confirm, bool echo, bool brefresh, const char *notice)
 {
 	bool ok;
 
@@ -89,7 +89,7 @@ open_external_viewer(const char *argv[],
 		set_terminal_modes();
 	}
 
-	if (watch_update(WATCH_EVENT_AFTER_COMMAND) && refresh) {
+	if (watch_update(WATCH_EVENT_AFTER_COMMAND) && brefresh) {
 		struct view *view;
 		int i;
 
