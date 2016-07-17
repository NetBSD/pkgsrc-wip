$NetBSD$

--- third_party/WebKit/Source/wtf/wtf.gyp.orig	2016-06-24 01:02:47.000000000 +0000
+++ third_party/WebKit/Source/wtf/wtf.gyp
@@ -57,7 +57,7 @@
       'target_name': 'wtf',
       'type': '<(component)',
       'include_dirs': [
-        '..',
+        '..', '<(prefix_dir)/include',
       ],
       'dependencies': [
           'wtf_config',
