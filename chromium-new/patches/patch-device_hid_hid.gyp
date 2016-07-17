$NetBSD$

--- device/hid/hid.gyp.orig	2016-06-24 01:02:22.000000000 +0000
+++ device/hid/hid.gyp
@@ -84,6 +84,18 @@
             },
           },
         }],
+        ['os_bsd==1', {
+          'sources!': [
+            'device_monitor_linux.cc',
+            'device_monitor_linux.h',
+            'hid_connection_linux.cc',
+            'hid_connection_linux.h',
+            'hid_service_linux.cc',
+            'hid_service_linux.h',
+            'input_service_linux.cc',
+            'input_service_linux.h',
+          ],
+        }],
       ],
     },
     {
