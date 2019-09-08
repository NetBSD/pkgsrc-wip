$NetBSD$

Add support for curses(3).

--- src/ui/core.c.orig	2017-01-28 21:10:04.000000000 +0000
+++ src/ui/core.c
@@ -54,6 +54,8 @@
 #include <ncursesw/ncurses.h>
 #elif HAVE_NCURSES_H
 #include <ncurses.h>
+#elif HAVE_CURSES_H
+#include <curses.h>
 #endif
 
 #include "log.h"
