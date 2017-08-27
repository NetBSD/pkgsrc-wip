$NetBSD$

Install `.desktop' file on other platforms that can use it.
The list is still probably still incomplete.

--- setup.py.orig	2016-07-06 20:31:17.000000000 +0000
+++ setup.py
@@ -64,7 +64,10 @@ options = dict(
     long_description=open("README.rst").read()
 )
 
-if sys.platform.startswith('linux'):
+if sys.platform.startswith('linux') or \
+   sys.platform.startswith('freebsd') or \
+   sys.platform.startswith('netbsd') or \
+   sys.platform.startswith('openbsd'):
     # Install desktop file. Required for mpris on Ubuntu
     options['data_files'] = [('share/applications/', ['mps-youtube.desktop'])]
 
