$NetBSD: patch-src_core.c,v 1.4 2012/05/07 08:45:17 imilh Exp $

--- src/core.c.orig	2012-05-03 21:08:27.000000000 +0000
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
@@ -1371,7 +1373,7 @@ void free_text_objects(struct text_objec
 	for (obj = root->prev; obj; obj = root->prev) {
 		root->prev = obj->prev;
 		switch (obj->type) {
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 			case OBJ_acpitemp:
 				close(data.i);
 				break;
@@ -1645,7 +1647,7 @@ void free_text_objects(struct text_objec
 #endif /* HAVE_LUA */
 			case OBJ_pre_exec:
 				break;
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 			case OBJ_battery:
 				free(data.s);
 				break;
