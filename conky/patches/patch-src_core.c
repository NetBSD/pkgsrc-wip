$NetBSD: patch-src_core.c,v 1.3 2012/05/06 10:46:15 imilh Exp $

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
@@ -75,6 +75,8 @@
 #include "freebsd.h"
 #elif defined(__OpenBSD__)
 #include "openbsd.h"
+#elif defined(__NetBSD__)
+#include "netbsd.h"
 #endif
 
 #include <string.h>
@@ -237,7 +239,7 @@ struct text_object *construct_text_objec
 
 #endif /* __linux__ */
 
-#ifndef __OpenBSD__
+#if !defined(__NetBSD__) && !defined(__OpenBSD__)
 	END OBJ(acpifan, 0)
 	END OBJ(battery, 0)
 		char bat[64];
@@ -1364,7 +1366,7 @@ void free_text_objects(struct text_objec
 	for (obj = root->prev; obj; obj = root->prev) {
 		root->prev = obj->prev;
 		switch (obj->type) {
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 			case OBJ_acpitemp:
 				close(data.i);
 				break;
@@ -1638,7 +1640,7 @@ void free_text_objects(struct text_objec
 #endif /* HAVE_LUA */
 			case OBJ_pre_exec:
 				break;
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 			case OBJ_battery:
 				free(data.s);
 				break;
