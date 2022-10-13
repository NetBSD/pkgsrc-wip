$NetBSD$

* The special case for NetBSD is not required, but prevents term.h from being
  found

--- src/ChezScheme/c/expeditor.c.orig	2022-07-08 06:15:57.000000000 +0000
+++ src/ChezScheme/c/expeditor.c
@@ -654,9 +654,6 @@ static void s_ee_set_color(int color_id,
 # define CHTYPE int
 # include </usr/include/curses.h>
 # include </usr/include/term.h>
-#elif defined(NETBSD)
-# include <ncurses.h>
-# include <ncurses/term.h>
 #else
 # include <curses.h>
 # include <term.h>
