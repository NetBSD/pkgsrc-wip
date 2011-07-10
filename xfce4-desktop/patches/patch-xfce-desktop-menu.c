$NetBSD: patch-xfce-desktop-menu.c,v 1.1 2011/07/10 15:05:36 reinoudz70 Exp $

--- /usr/tmp/pkgsrc-diablo/wip/xfce4-desktop/work/xfdesktop-4.8.2/src/xfce-desktop-menu.c.orig	2011-04-22 18:21:52.000000000 +0000
+++ /usr/tmp/pkgsrc-diablo/wip/xfce4-desktop/work/xfdesktop-4.8.2/src/xfce-desktop-menu.c
@@ -203,8 +203,13 @@ _generate_menu(XfceDesktopMenu *desktop_
         return FALSE;
     }
 
+#if 0
+    /* no idea what goes wrong here, but this constantly updates the menu over and
+     * over again and thus saves around 100% cpu! :)
+     */
     g_signal_connect_swapped(desktop_menu->garcon_menu, "reload-required",
                              G_CALLBACK(xfce_desktop_menu_reload), desktop_menu);
+#endif
 
     return ret;
 }
