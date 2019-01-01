$NetBSD$

date: 2013-10-07 04:59:42 +0900;  author: joerg;  state: Exp;  commitid: SFTb57hmh7OOQg8x;
Update GDL to 3.10.0 for the Gnome 3 version.

--- gdl/gdl-dock-bar.c.orig	2014-01-14 05:49:11.000000000 +0900
+++ gdl/gdl-dock-bar.c	2019-01-01 22:31:00.631126196 +0900
@@ -484,7 +484,7 @@ GdlDockBarStyle gdl_dock_bar_get_style(G
 {
     GdlDockBarStyle style;
 
-    g_return_val_if_fail (GDL_IS_DOCK_BAR (dockbar), 0);
+    g_return_val_if_fail (GDL_IS_DOCK_BAR (dockbar), GDL_DOCK_BAR_AUTO);
 
     g_object_get(G_OBJECT(dockbar), "dockbar-style", &style, NULL);
 
