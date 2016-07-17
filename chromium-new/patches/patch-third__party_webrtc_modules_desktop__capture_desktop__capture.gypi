$NetBSD$

--- third_party/webrtc/modules/desktop_capture/desktop_capture.gypi.orig	2016-06-24 01:04:15.000000000 +0000
+++ third_party/webrtc/modules/desktop_capture/desktop_capture.gypi
@@ -114,6 +114,11 @@
             ],
           },
         }],
+        ['os_bsd==1', {
+          'include_dirs': [
+            '<(prefix_dir)/include',
+          ],
+        }],
         ['OS!="win" and OS!="mac" and use_x11==0', {
           'sources': [
             "mouse_cursor_monitor_null.cc",
