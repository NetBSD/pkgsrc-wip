$NetBSD$

--- printrun/utils.py.orig	2017-11-01 16:18:44.000000000 +0000
+++ printrun/utils.py
@@ -28,8 +28,8 @@ import logging
 def install_locale(domain):
     if os.path.exists('/usr/share/pronterface/locale'):
         gettext.install(domain, '/usr/share/pronterface/locale', unicode = 1)
-    elif os.path.exists('/usr/local/share/pronterface/locale'):
-        gettext.install(domain, '/usr/local/share/pronterface/locale',
+    elif os.path.exists('/usr/pkg/share/pronterface/locale'):
+        gettext.install(domain, '/usr/pkg/share/pronterface/locale',
                         unicode = 1)
     else:
         gettext.install(domain, './locale', unicode = 1)
@@ -71,7 +71,7 @@ def iconfile(filename):
         return pixmapfile(filename)
 
 def imagefile(filename):
-    for prefix in ['/usr/local/share/pronterface/images',
+    for prefix in ['/usr/pkg/share/pronterface/images','/usr/local/share/pronterface/images',
                    '/usr/share/pronterface/images']:
         candidate = os.path.join(prefix, filename)
         if os.path.exists(candidate):
@@ -94,11 +94,11 @@ def lookup_file(filename, prefixes):
     return filename
 
 def pixmapfile(filename):
-    return lookup_file(filename, ['/usr/local/share/pixmaps',
+    return lookup_file(filename, ['/usr/pkg/share/pixmaps','/usr/local/share/pixmaps',
                                   '/usr/share/pixmaps'])
 
 def sharedfile(filename):
-    return lookup_file(filename, ['/usr/local/share/pronterface',
+    return lookup_file(filename, ['/usr/pkg/share/pronterface','/usr/local/share/pronterface',
                                   '/usr/share/pronterface'])
 
 def configfile(filename):
