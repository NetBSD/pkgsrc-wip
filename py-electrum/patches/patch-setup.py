$NetBSD$

Unconditional installation of data files.

--- setup.py.orig	2000-11-11 11:11:11.000000000 +0000
+++ setup.py
@@ -30,15 +30,11 @@ version_spec = importlib.util.spec_from_
 version_module = version = importlib.util.module_from_spec(version_spec)
 version_spec.loader.exec_module(version_module)
 
-data_files = []
-
-if platform.system() in ['Linux', 'FreeBSD', 'DragonFly']:
-    # note: we can't use absolute paths here. see #7787
-    data_files += [
-        (os.path.join('share', 'applications'),               ['electrum.desktop']),
-        (os.path.join('share', 'pixmaps'),                    ['electrum/gui/icons/electrum.png']),
-        (os.path.join('share', 'icons/hicolor/128x128/apps'), ['electrum/gui/icons/electrum.png']),
-    ]
+data_files = [
+    (os.path.join('share', 'applications'),               ['electrum.desktop']),
+    (os.path.join('share', 'pixmaps'),                    ['electrum/gui/icons/electrum.png']),
+    (os.path.join('share', 'icons/hicolor/128x128/apps'), ['electrum/gui/icons/electrum.png']),
+]
 
 extras_require = {
     'hardware': requirements_hw,
