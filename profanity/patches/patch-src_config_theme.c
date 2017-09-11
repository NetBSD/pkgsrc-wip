$NetBSD$

Add support for curses(3).

--- src/config/theme.c.orig	2017-01-28 21:10:04.000000000 +0000
+++ src/config/theme.c
@@ -43,6 +43,12 @@
 #include <ncursesw/ncurses.h>
 #elif HAVE_NCURSES_H
 #include <ncurses.h>
+#elif HAVE_CURSES_H
+#include <curses.h>
+#endif
+
+#ifndef NCURSES_COLOR_T
+#define NCURSES_COLOR_T short
 #endif
 
 #include "common.h"
