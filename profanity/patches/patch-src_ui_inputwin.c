$NetBSD$

Add support for curses(3).

--- src/ui/inputwin.c.orig	2017-01-28 21:10:04.000000000 +0000
+++ src/ui/inputwin.c
@@ -51,6 +51,8 @@
 #include <ncursesw/ncurses.h>
 #elif HAVE_NCURSES_H
 #include <ncurses.h>
+#elif HAVE_CURSES_H
+#include <curses.h>
 #endif
 
 #include "profanity.h"
@@ -282,7 +284,8 @@ _inp_win_update_virtual(void)
 {
     int wrows, wcols;
     getmaxyx(stdscr, wrows, wcols);
-    pnoutrefresh(inp_win, 0, pad_start, wrows-1, 0, wrows-1, wcols-2);
+    if (inp_win != NULL)
+	    pnoutrefresh(inp_win, 0, pad_start, wrows-1, 0, wrows-1, wcols-2);
 }
 
 static void
