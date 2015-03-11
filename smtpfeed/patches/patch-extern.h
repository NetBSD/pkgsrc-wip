$NetBSD: patch-extern.h,v 1.1 2015/03/11 14:37:02 makoto Exp $

show_query returns nothing

--- extern.h.orig	2012-06-07 16:51:47.000000000 +0900
+++ extern.h	2015-03-11 23:25:59.000000000 +0900
@@ -68,6 +68,11 @@ void hash_domain_rcpts_enter();
 int isnumeric();
 int rcpts_def_load();
 
+void show_query(u_char* t, u_char* b, u_char* e);
+//u_char *t, *b, *e;
+//{
+
+
 void initsetproctitle();
 #ifdef JAZ_HACK2
 void show_cache();
