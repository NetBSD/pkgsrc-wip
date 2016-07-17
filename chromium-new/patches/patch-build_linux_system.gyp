$NetBSD$

--- build/linux/system.gyp.orig	2016-06-24 01:02:09.000000000 +0000
+++ build/linux/system.gyp
@@ -1051,6 +1051,13 @@
       'include_dirs': [
         '../..',
       ],
+      'conditions' : [
+        ['OS=="freebsd" or OS=="netbsd"', {
+          'include_dirs': [
+            '<(prefix_dir)/include',
+          ],
+        }],
+      ],
       'hard_dependency': 1,
       'actions': [
         {
