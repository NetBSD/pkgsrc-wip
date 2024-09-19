$NetBSD: patch-setup.py,v 1.1 2011/12/28 23:39:10 jihbed Exp $

--- setup.py.orig	2011-12-29 00:06:39.000000000 +0100
+++ setup.py	2011-12-29 00:07:14.000000000 +0100
@@ -9,6 +9,7 @@
 from subprocess import *
 import os
 import glob
+import sys
 
 DFEET_VERSION='0.1.14'
 
@@ -56,7 +57,7 @@
     download_url='http://live.gnome.org/d-feet/',
     license='GNU GPL',
     platforms='linux',
-    scripts=['d-feet'],
+    scripts=['d-feet'+sys.version[0:3]],
     packages=['dfeet', 'dfeet/_ui'],
     data_files=[
         ('share/dfeet', glob.glob("ui/*.ui")),
