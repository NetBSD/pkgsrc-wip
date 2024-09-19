$NetBSD: patch-lib_utils_autostart.py,v 1.1 2013/12/21 15:14:09 noud4 Exp $

Use pkgsrc path.

--- lib/utils/autostart.py.orig	2013-12-18 22:03:11.000000000 +0000
+++ lib/utils/autostart.py
@@ -15,7 +15,7 @@ class AutoStart(object):
         self.entry = DesktopEntry()
 
         filename = '%s.desktop' % app_name
-        system_entry = os.path.join('/usr/share/applications/', filename)
+        system_entry = os.path.join('@PREFIX@/share/applications/', filename)
         self.local_entry = os.path.join(xdg_config_home, 'autostart', filename)
         self.key = 'X-GNOME-Autostart-enabled'
 
