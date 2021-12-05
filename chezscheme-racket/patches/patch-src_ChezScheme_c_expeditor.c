$NetBSD$

* The special case for NetBSD is not required, but prevents term.h from being
  found

--- src/ChezScheme/c/expeditor.c.orig	2021-10-24 04:17:58.000000000 +0000
+++ src/ChezScheme/c/expeditor.c
@@ -541,7 +541,7 @@ static void s_ee_write_char(wchar_t c) {
 # include </usr/include/term.h>
 #elif defined(NETBSD)
 # include <ncurses.h>
-# include <ncurses/term.h>
+# include <term.h>
 #else
 # include <curses.h>
 # include <term.h>
