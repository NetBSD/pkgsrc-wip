$NetBSD$

--- third_party/sfntly/sfntly.gyp.orig	2016-06-24 01:02:49.000000000 +0000
+++ third_party/sfntly/sfntly.gyp
@@ -127,6 +127,7 @@
       ],
       'include_dirs': [
         'src/cpp/src',
+        '<(prefix_dir)/include',
       ],
       # This macro must be define to suppress the use of exception
       'defines': [
