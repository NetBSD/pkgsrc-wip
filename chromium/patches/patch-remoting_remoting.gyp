$NetBSD: patch-remoting_remoting.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- remoting/remoting.gyp.orig	2011-04-13 08:01:07.000000000 +0000
+++ remoting/remoting.gyp
@@ -16,7 +16,7 @@
   },
 
   'conditions': [
-    ['OS=="linux" or OS=="mac"', {
+    ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="mac"', {
       'targets': [
         # Simple webserver for testing chromoting client plugin.
         {
@@ -30,7 +30,7 @@
     }],
 
     # TODO(hclam): Enable this target for mac.
-    ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+    ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
 
       'targets': [
         {
@@ -40,15 +40,25 @@
             'chromoting_base',
             'chromoting_client',
             'chromoting_jingle_glue',
+            '../build/linux/system.gyp:x11',
+            '../build/linux/system.gyp:xext',
           ],
           'link_settings': {
             'libraries': [
-              '-ldl',
               '-lX11',
               '-lXrender',
               '-lXext',
             ],
           },
+          'conditions': [
+            ['OS=="linux"', {
+              'link_settings': {
+                'libraries': [
+                  '-ldl',
+                ],
+              },
+            }],
+          ],
           'sources': [
             'client/x11_client.cc',
             'client/x11_input_handler.cc',
@@ -99,7 +109,7 @@
             '../media/base/yuv_row_win.cc',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="mac"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="mac"', {
           'sources': [
             '../media/base/yuv_row_posix.cc',
           ],
@@ -221,7 +231,11 @@
             'host/event_executor_win.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
+          'dependencies': [
+            '../build/linux/system.gyp:x11',
+            '../build/linux/system.gyp:xext',
+          ],
           'sources': [
             'host/capturer_linux.cc',
             'host/capturer_linux.h',
@@ -233,6 +247,7 @@
               '-lX11',
               '-lXdamage',
               '-lXtst',
+              '-lvpx',
             ],
           },
         }],
@@ -500,7 +515,7 @@
             'host/capturer_gdi_unittest.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             # Needed for the following #include chain:
             #   base/run_all_unittests.cc
