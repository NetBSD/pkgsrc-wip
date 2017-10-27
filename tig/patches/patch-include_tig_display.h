$NetBSD$

`newscr' is present only in curses, not in POSIX curses. Use `curscr' instead.

XXX: Is this correct?

--- include/tig/display.h.orig	2017-09-29 15:15:26.000000000 +0000
+++ include/tig/display.h
@@ -58,8 +58,8 @@ void enable_mouse(bool enable);
 
 enum status_code open_script(const char *path);
 
-#define get_cursor_pos(cursor_y, cursor_x) getyx(newscr, cursor_y, cursor_x)
-#define set_cursor_pos(cursor_y, cursor_x) wmove(newscr, cursor_y, cursor_x)
+#define get_cursor_pos(cursor_y, cursor_x) getyx(curscr, cursor_y, cursor_x)
+#define set_cursor_pos(cursor_y, cursor_x) wmove(curscr, cursor_y, cursor_x)
 
 #endif
 /* vim: set ts=8 sw=8 noexpandtab: */
