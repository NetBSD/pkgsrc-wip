$NetBSD$

--- src/gui/curses/gui-curses-term.c.orig	2015-08-16 06:27:07.000000000 +0000
+++ src/gui/curses/gui-curses-term.c
@@ -45,7 +45,7 @@
 void
 gui_term_set_eat_newline_glitch (int value)
 {
-#ifdef HAVE_EAT_NEWLINE_GLITCH
+#if defined(HAVE_EAT_NEWLINE_GLITCH) && !defined(__NetBSD__)
     eat_newline_glitch = value;
 #else
     /* make C compiler happy */
