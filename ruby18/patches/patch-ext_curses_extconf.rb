$NetBSD$

--- ext/curses/extconf.rb.orig	2007-11-15 10:51:07.000000000 +0000
+++ ext/curses/extconf.rb
@@ -11,9 +11,6 @@ elsif have_header(*curses=%w"ncurses/curses.h") and ha
   make=true
 elsif have_header(*curses=%w"ncurses/curses.h") and have_library("ncurses", "initscr")
   make=true
-elsif have_header(*curses=%w"curses_colr/curses.h") and have_library("cur_colr", "initscr")
-  curses.unshift("varargs.h")
-  make=true
 elsif have_header(*curses=%w"curses.h") and have_library("curses", "initscr")
   make=true
 end
