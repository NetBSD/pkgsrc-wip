$NetBSD: patch-gnome_app.py,v 1.1 2012/12/27 19:52:23 ryo-on Exp $

--- gnome/app.py.orig	2011-06-05 11:28:51.000000000 +0000
+++ gnome/app.py
@@ -1214,7 +1214,7 @@ if __name__ == '__main__':
 
     app_instance = guiapplicationinstance.GUIApplicationInstance( cfg.get_app_instance_file(), raise_cmd )
 
-    gnome_props = { gnome.PARAM_APP_DATADIR : '/usr/share' }
+    gnome_props = { gnome.PARAM_APP_DATADIR : '@PREFIX@' }
     gnome.program_init( 'backintime', cfg.VERSION, properties = gnome_props )
 
     gtk.about_dialog_set_url_hook( open_url, None )
