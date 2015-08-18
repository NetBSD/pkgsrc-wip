$NetBSD: patch-setup.py,v 1.1 2015/08/18 18:36:32 yhardy Exp $

Use the correct directory for man pages (man pages moved in post-extract)

--- setup.py.orig	2015-02-27 18:25:32.000000000 +0000
+++ setup.py
@@ -31,6 +31,8 @@ m['packages'] = ['.'.join(dirname.split(
         for dirname, _, files in os.walk('lib') if '__init__.py' in files]
 m['data_files'] = [(dirname, [os.path.join(dirname, file) for file in files])
         for dirname, _, files in os.walk('share')]
+m['data_files'] = m['data_files'] + [(dirname, [os.path.join(dirname, file) for file in files])
+        for dirname, _, files in os.walk('man')]
 
 setup(**m)
 
