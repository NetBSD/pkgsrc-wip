$NetBSD: patch-setup.py,v 1.1.1.1 2011/12/27 14:03:09 jihbed Exp $

--- setup.py.orig	2011-12-26 16:19:50.000000000 +0100
+++ setup.py	2011-12-26 16:20:24.000000000 +0100
@@ -109,7 +109,7 @@
           "Topic :: Scientific/Engineering :: Mathematics",
       ],
       long_description=open('README.txt').read(),
-      scripts=['bin/aesthete_ime'],\
+      scripts=['bin/aesthete_ime'+sys.version[0:3]],\
       data_files=[
           ('share/applications', glob.glob('share/aesthete.desktop')),
           ('share/icons/hicolor/scalable/apps/', glob.glob('share/icons/scalable/apps/*.svg')),
