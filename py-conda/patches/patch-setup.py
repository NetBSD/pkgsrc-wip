$NetBSD: patch-setup.py,v 1.1 2014/10/04 21:41:46 jihbed Exp $

--- setup.py.orig	2014-10-04 22:32:19.000000000 +0100
+++ setup.py	2014-10-04 22:34:18.000000000 +0100
@@ -42,7 +42,7 @@
     kwds['entry_points'] = dict(console_scripts =
                                         ["conda = conda.cli.main:main"])
 else:
-    kwds['scripts'].append('bin/conda')
+    kwds['scripts'].append('bin/conda'+sys.version[0:3])
 
 if add_activate:
     if sys.platform == 'win32':
@@ -53,7 +53,6 @@
 setup(
     name = "conda",
     version='3.5.0',
-    
     author = "Continuum Analytics, Inc.",
     author_email = "ilan@continuum.io",
     url = "https://github.com/conda/conda",
