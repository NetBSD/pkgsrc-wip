$NetBSD$

Add support for curses(3).

--- src/ui/window.c.orig	2017-01-28 21:10:04.000000000 +0000
+++ src/ui/window.c
@@ -46,6 +46,8 @@
 #include <ncursesw/ncurses.h>
 #elif HAVE_NCURSES_H
 #include <ncurses.h>
+#elif HAVE_CURSES_H
+#include <curses.h>
 #endif
 
 #include "config/theme.h"
