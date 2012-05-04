$NetBSD: patch-src_core.c,v 1.2 2012/05/04 10:57:24 imilh Exp $

NetBSD's curses are good enough, use portable header file name.

--- src/core.c.orig	2010-10-05 21:29:36.000000000 +0000
+++ src/core.c
@@ -65,7 +65,7 @@
 #include "top.h"
 
 #ifdef NCURSES
-#include <ncurses.h>
+#include <curses.h>
 #endif
 
 /* check for OS and include appropriate headers */
@@ -75,6 +75,7 @@
 #include "freebsd.h"
 #elif defined(__OpenBSD__)
 #include "openbsd.h"
+#elif defined(__NetBSD__)
 #endif
 
 #include <string.h>
@@ -237,7 +238,7 @@ struct text_object *construct_text_objec
 
 #endif /* __linux__ */
 
-#ifndef __OpenBSD__
+#if !defined(__NetBSD__) && !defined(__OpenBSD__)
 	END OBJ(acpifan, 0)
 	END OBJ(battery, 0)
 		char bat[64];
