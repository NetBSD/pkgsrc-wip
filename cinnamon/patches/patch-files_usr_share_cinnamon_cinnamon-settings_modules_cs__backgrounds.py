$NetBSD$

Point to gnome backgrounds.

--- files/usr/share/cinnamon/cinnamon-settings/modules/cs_backgrounds.py.orig	2018-05-06 15:13:24.000000000 +0000
+++ files/usr/share/cinnamon/cinnamon-settings/modules/cs_backgrounds.py
@@ -268,7 +268,7 @@ class Module:
     def get_system_backgrounds(self):
         picture_list = []
         folder_list = []
-        properties_dir = "/usr/share/cinnamon-background-properties"
+        properties_dir = "/usr/share/gnome-background-properties"
         backgrounds = []
         if os.path.exists(properties_dir):
             for i in os.listdir(properties_dir):
