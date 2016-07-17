$NetBSD$

--- native_client/build/common.gypi.orig	2016-06-24 01:03:25.000000000 +0000
+++ native_client/build/common.gypi
@@ -58,7 +58,7 @@
     ],
   },
   'conditions': [
-    ['OS=="linux" or OS=="android"', {
+    ['OS=="linux" or OS=="android" or OS=="freebsd"', {
       'target_defaults': {
         'defines': [
           '_POSIX_C_SOURCE=199506',
