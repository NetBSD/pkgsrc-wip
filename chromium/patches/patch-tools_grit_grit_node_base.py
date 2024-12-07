$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/grit/grit/node/base.py.orig	2024-12-03 23:30:50.619506400 +0000
+++ tools/grit/grit/node/base.py
@@ -498,7 +498,8 @@ class Node:
         value = defs
 
       elif name == 'is_linux':
-        value = target_platform == 'linux'
+        value = (target_platform == 'linux'
+                 or 'bsd' in target_platform)
       elif name == 'is_chromeos':
         value = target_platform == 'chromeos'
       elif name == 'is_macosx':
