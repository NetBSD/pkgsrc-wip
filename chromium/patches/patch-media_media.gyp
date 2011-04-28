$NetBSD: patch-media_media.gyp,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- media/media.gyp.orig	2011-04-13 08:01:07.000000000 +0000
+++ media/media.gyp
@@ -171,14 +171,14 @@
             'video/mft_h264_decode_engine.h',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="freebsd" or OS=="dragonfly"', {
           'link_settings': {
             'libraries': [
               '-lasound',
             ],
           },
         }],
-        ['OS=="openbsd"', {
+        ['OS=="openbsd" or OS=="netbsd"', {
           'sources/': [ ['exclude', 'alsa_' ],
                         ['exclude', 'audio_manager_linux' ],
                         ['exclude', '\\.mm?$' ] ],
@@ -187,13 +187,13 @@
             ],
           },
         }],
-        ['OS!="openbsd"', {
+        ['OS!="openbsd" and OS!="netbsd"', {
           'sources!': [
             'audio/openbsd/audio_manager_openbsd.cc',
             'audio/openbsd/audio_manager_openbsd.h',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'sources': [
             'filters/omx_video_decoder.cc',
             'filters/omx_video_decoder.h',
@@ -229,7 +229,7 @@
         'ffmpeg/ffmpeg_unittest.cc',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'dependencies': [
             # Needed for the following #include chain:
             #   base/run_all_unittests.cc
@@ -308,7 +308,12 @@
         'video/ffmpeg_video_decode_engine_unittest.cc',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="netbsd" or OS=="openbsd"', {
+          'sources!': [
+            'audio/linux/alsa_output_unittest.cc',
+          ],
+        }],
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'dependencies': [
             # Needed for the following #include chain:
             #   base/run_all_unittests.cc
@@ -507,7 +512,7 @@
             'tools/shader_bench/window.h',
           ],
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
               'dependencies': [
                 '../build/linux/system.gyp:gtk',
               ],
@@ -528,7 +533,7 @@
         },
       ],
     }],
-    ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+    ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
       'targets': [
         {
           'target_name': 'omx_test',
@@ -560,7 +565,7 @@
             '../testing/gtest.gyp:gtest',
           ],
           'conditions': [
-            ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+            ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
               'dependencies': [
                 '../build/linux/system.gyp:gtk',
               ],
@@ -600,12 +605,20 @@
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
             'tools/player_x11/player_x11.cc',
           ],
