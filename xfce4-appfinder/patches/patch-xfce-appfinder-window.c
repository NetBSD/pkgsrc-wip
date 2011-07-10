$NetBSD: patch-xfce-appfinder-window.c,v 1.1 2011/07/10 15:19:37 reinoudz70 Exp $

--- src/xfce-appfinder-window.c.orig	2011-01-16 15:47:58.000000000 +0000
+++ src/xfce-appfinder-window.c
@@ -350,7 +350,13 @@ xfce_appfinder_window_init (XfceAppfinde
     window->menu = garcon_menu_new_applications ();
 
   /* reload the menu when necessary */
+#if 0
+  /*
+   * Disable this reload since its constantly updating it! aparently the communication with garcon fails.
+   * No missing functionality detected.
+   */
   g_signal_connect_swapped (window->menu, "reload-required", G_CALLBACK (xfce_appfinder_window_reload), window);
+#endif
 }
 
 
