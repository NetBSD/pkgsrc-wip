$NetBSD: patch-setup.py,v 1.1.1.1 2012/08/25 17:02:04 jihbed Exp $

--- setup.py.orig	2010-07-13 17:12:13.000000000 +0100
+++ setup.py	2012-02-04 15:57:50.000000000 +0100
@@ -1,6 +1,7 @@
 #!/usr/bin/env python
 
 import os
+import sys
 
 from distutils.core import setup
 from distutils.command.build import build
@@ -136,7 +137,7 @@
               ],
     data_files=[
                 ('share/applications', ['share/applications/dreampie.desktop']),
-                ('share/man/man1', ['share/man/man1/dreampie.1']),
+                ('man/man1', ['share/man/man1/dreampie.1']),
                 ('share/pixmaps', ['share/pixmaps/dreampie.svg',
                                    'share/pixmaps/dreampie.png']),
                 ('share/dreampie', ['share/dreampie/subp_main.py',
