$NetBSD: patch-common-src_glib-util.c,v 1.1 2012/07/12 06:53:11 schnoebe Exp $

Remove an unused function that conflicts with a glib 2.28+ routine
(which has a different signature)

--- common-src/glib-util.c.orig	2012-02-21 11:36:51.000000000 +0000
+++ common-src/glib-util.c
@@ -120,15 +120,6 @@ void slist_free_full(GSList * list, GDes
 }
 #endif
 
-void g_queue_free_full(GQueue * queue) {
-    while (!g_queue_is_empty(queue)) {
-        gpointer data;
-        data = g_queue_pop_head(queue);
-        amfree(data);
-    }
-    g_queue_free(queue);
-}
-
 void g_ptr_array_free_full(GPtrArray * array) {
     size_t i;
 
