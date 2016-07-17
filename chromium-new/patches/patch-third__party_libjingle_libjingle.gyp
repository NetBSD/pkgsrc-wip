$NetBSD$

--- third_party/libjingle/libjingle.gyp.orig	2016-06-24 01:02:48.000000000 +0000
+++ third_party/libjingle/libjingle.gyp
@@ -121,6 +121,8 @@
         ['os_bsd==1', {
           'defines': [
             'BSD',
+            'WEBRTC_LINUX',
+            'WEBRTC_BSD',
           ],
         }],
         ['OS=="openbsd"', {
@@ -191,6 +193,8 @@
       ['os_bsd==1', {
         'defines': [
           'BSD',
+          'WEBRTC_LINUX',
+          'WEBRTC_BSD',
         ],
       }],
       ['OS=="openbsd"', {
