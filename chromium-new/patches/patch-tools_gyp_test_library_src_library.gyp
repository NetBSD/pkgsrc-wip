$NetBSD$

--- tools/gyp/test/library/src/library.gyp.orig	2016-06-24 01:04:17.000000000 +0000
+++ tools/gyp/test/library/src/library.gyp
@@ -48,7 +48,7 @@
     },
   ],
   'conditions': [
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'target_defaults': {
         # Support 64-bit shared libs (also works fine for 32-bit).
         'cflags': ['-fPIC'],
