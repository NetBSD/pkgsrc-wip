$NetBSD: patch-tools_gyp_test_additional-targets_src_dir1_actions.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- tools/gyp/test/additional-targets/src/dir1/actions.gyp.orig	2011-04-13 08:13:18.000000000 +0000
+++ tools/gyp/test/additional-targets/src/dir1/actions.gyp
@@ -47,7 +47,7 @@
     },
   ],
   'conditions': [
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
       'target_defaults': {
         'cflags': ['-fPIC'],
       },
