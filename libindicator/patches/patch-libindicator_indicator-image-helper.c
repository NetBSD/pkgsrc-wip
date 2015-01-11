$NetBSD: patch-libindicator_indicator-image-helper.c,v 1.1 2015/01/11 08:12:32 obache Exp $

* prevent to use deprecated API

--- libindicator/indicator-image-helper.c.orig	2012-09-19 15:38:05.000000000 +0000
+++ libindicator/indicator-image-helper.c
@@ -69,7 +69,11 @@ refresh_image (GtkImage * image)
 	GdkPixbuf * pixbuf = gdk_pixbuf_new_from_file(icon_filename, &error);
 
 	if (icon_info != NULL) {
+#if GTK_CHECK_VERSION(3, 8, 0)
+		g_object_unref(icon_info);
+#else
 		gtk_icon_info_free(icon_info);
+#endif
 	}
 
 	if (pixbuf == NULL) {
