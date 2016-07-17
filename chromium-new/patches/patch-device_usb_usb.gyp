$NetBSD$

--- device/usb/usb.gyp.orig	2016-06-24 01:02:22.000000000 +0000
+++ device/usb/usb.gyp
@@ -117,6 +117,16 @@
             'usb_service_impl.h',
           ]
         }],
+        ['OS == "freebsd"', {
+          'dependencies!': [
+            '../../third_party/libusb/libusb.gyp:libusb',
+          ],
+          'link_settings': {
+            'ldflags': [
+              '-L/usr/lib -lusb',
+            ],
+          },
+        }],
         ['chromeos==1', {
           'dependencies': [
             '../../chromeos/chromeos.gyp:chromeos',
