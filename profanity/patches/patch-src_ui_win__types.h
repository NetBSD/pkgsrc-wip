$NetBSD$

Add support for curses(3).

--- src/ui/win_types.h.orig	2017-01-28 21:10:04.000000000 +0000
+++ src/ui/win_types.h
@@ -44,6 +44,8 @@
 #include <ncursesw/ncurses.h>
 #elif HAVE_NCURSES_H
 #include <ncurses.h>
+#elif HAVE_CURSES_H
+#include <curses.h>
 #endif
 
 #include "tools/autocomplete.h"
