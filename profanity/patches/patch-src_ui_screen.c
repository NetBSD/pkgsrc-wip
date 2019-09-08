$NetBSD$

--- src/ui/screen.c.orig	2019-06-10 12:19:05.000000000 +0000
+++ src/ui/screen.c
@@ -38,6 +38,8 @@
 #include <ncursesw/ncurses.h>
 #elif HAVE_NCURSES_H
 #include <ncurses.h>
+#elif HAVE_CURSES_H
+#include <curses.h>
 #endif
 
 #include "config/preferences.h"
