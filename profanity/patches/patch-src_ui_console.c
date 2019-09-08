$NetBSD$

Add support for curses(3).

--- src/ui/console.c.orig	2017-01-28 21:10:04.000000000 +0000
+++ src/ui/console.c
@@ -41,6 +41,8 @@
 #include <ncursesw/ncurses.h>
 #elif HAVE_NCURSES_H
 #include <ncurses.h>
+#elif HAVE_CURSES_H
+#include <curses.h>
 #endif
 
 #include "common.h"
