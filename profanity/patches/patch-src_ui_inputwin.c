$NetBSD$

Add support for curses(3).

--- src/ui/inputwin.c.orig	2019-06-10 12:19:05.000000000 +0000
+++ src/ui/inputwin.c
@@ -51,6 +51,8 @@
 #include <ncursesw/ncurses.h>
 #elif HAVE_NCURSES_H
 #include <ncurses.h>
+#elif HAVE_CURSES_H
+#include <curses.h>
 #endif
 
 #include "profanity.h"
@@ -285,7 +287,8 @@ _inp_win_update_virtual(void)
 {
     int wcols = getmaxx(stdscr);
     int row = screen_inputwin_row();
-    pnoutrefresh(inp_win, 0, pad_start, row, 0, row, wcols-2);
+    if (inp_win != NULL)
+        pnoutrefresh(inp_win, 0, pad_start, row, 0, row, wcols-2);
 }
 
 static void
