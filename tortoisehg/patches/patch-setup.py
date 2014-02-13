$NetBSD: patch-setup.py,v 1.1 2014/02/13 19:05:33 nros Exp $
* nautilus-python is not available in pkgsrc so don't install
* the nautilus extention.
* Install html documention, desktop file and license file.
--- setup.py.orig	2013-11-16 07:12:03.000000000 +0000
+++ setup.py
@@ -504,8 +504,12 @@ def setup_posix():
     _data_files += [(os.path.join('share', root),
         [os.path.join(root, file_) for file_ in files])
         for root, dirs, files in os.walk('locale')]
-    _data_files += [('/usr/share/nautilus-python/extensions/',
-                     ['contrib/nautilus-thg.py'])]
+    _data_files += [(os.path.join('share/doc/tortoisehg', root),
+        [os.path.join(root, file_) for file_ in files])
+        for root, dirs, files in os.walk('html')]
+    _data_files += [('share/doc/tortoisehg/',['COPYING.txt'])]
+    _data_files += [('share/applications', ['thg.desktop'])]
+    _data_files += [('share/tortoisehg', ['mergetools.rc'])]
 
     # Create a config.py.  Distributions will need to supply their own
     cfgfile = os.path.join('tortoisehg', 'util', 'config.py')
