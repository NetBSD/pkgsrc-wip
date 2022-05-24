$NetBSD$

* The special case for NetBSD is not required, but prevents term.h from being
  found

--- src/ChezScheme/c/expeditor.c.orig	2021-10-24 04:17:58.000000000 +0000
+++ src/ChezScheme/c/expeditor.c
@@ -539,9 +539,6 @@ static void s_ee_write_char(wchar_t c) {
 # define CHTYPE int
 # include </usr/include/curses.h>
 # include </usr/include/term.h>
-#elif defined(NETBSD)
-# include <ncurses.h>
-# include <ncurses/term.h>
 #else
 # include <curses.h>
 # include <term.h>
