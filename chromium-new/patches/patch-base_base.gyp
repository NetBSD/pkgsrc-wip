$NetBSD$

--- base/base.gyp.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/base.gyp
@@ -114,7 +114,7 @@
           ],
           'link_settings': {
             'libraries': [
-              '-L/usr/local/lib -lexecinfo',
+              '-L/usr/local/lib -lexecinfo -lkvm',
             ],
           },
         }],
@@ -763,6 +763,11 @@
             'sync_socket_unittest.cc',
           ],
         }],
+        ['OS == "freebsd"', {
+          'sources!': [
+            'debug/proc_maps_linux_unittest.cc',
+          ],
+        }],
       ],  # target_conditions
     },
     {
