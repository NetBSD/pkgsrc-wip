$NetBSD$

--- tools/gyp/test/additional-targets/src/dir1/actions.gyp.orig	2016-06-24 01:04:17.000000000 +0000
+++ tools/gyp/test/additional-targets/src/dir1/actions.gyp
@@ -47,7 +47,7 @@
     },
   ],
   'conditions': [
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'target_defaults': {
         'cflags': ['-fPIC'],
       },
