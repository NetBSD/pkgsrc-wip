$NetBSD$

Compiler does not find the symbol on NetBSD.
TODO: resolve, and remove this patch!

--- navit/graphics/opengl/graphics_opengl.c.orig	2018-04-20 17:02:39.000000000 +0000
+++ navit/graphics/opengl/graphics_opengl.c
@@ -1723,10 +1723,10 @@ graphics_opengl_new(struct navit *nav, s
 #endif
 	this->DLid = glGenLists(1);
 
-	g_timeout_add(G_PRIORITY_DEFAULT + 10, graphics_opengl_idle, NULL);
+	g_timeout_add(10, graphics_opengl_idle, NULL);
 
 	/*this will only refresh screen in map(overlay enabled) mode */
-	g_timeout_add(G_PRIORITY_DEFAULT + 1000, redraw_filter, this);
+	g_timeout_add(1000, redraw_filter, this);
 #endif
 
 	//create hash table for uncompressed image data
