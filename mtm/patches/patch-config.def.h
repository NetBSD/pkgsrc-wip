$NetBSD$

NetBSD also uses util.h

--- config.def.h.orig	2021-10-08 20:38:13.000000000 +0000
+++ config.def.h
@@ -63,6 +63,8 @@
 #ifndef NCURSESW_INCLUDE_H
     #if defined(__APPLE__) || !defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
         #define NCURSESW_INCLUDE_H <curses.h>
+    #elif defined(__NetBSD__)
+        #define NCURSESW_INCLUDE_H <ncurses/curses.h>
     #else
         #define NCURSESW_INCLUDE_H <ncursesw/curses.h>
     #endif
@@ -71,7 +73,7 @@
 
 /* Includes needed to make forkpty(3) work. */
 #ifndef FORKPTY_INCLUDE_H
-    #if defined(__APPLE__) || defined(__OpenBSD__)
+    #if defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__)
         #define FORKPTY_INCLUDE_H <util.h>
     #elif defined(__FreeBSD__)
         #define FORKPTY_INCLUDE_H <libutil.h>
