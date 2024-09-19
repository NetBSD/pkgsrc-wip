$NetBSD$

--- setup.py.orig	2016-03-31 15:02:25.000000000 +0000
+++ setup.py
@@ -64,7 +64,7 @@ if 'bsd' in sys.platform:
     modules = [
         Extension('hid',
             sources = ['hid.pyx', 'chid.pxd', hidapi_src('libusb')],
-            include_dirs = [hidapi_include, '/usr/include/libusb-1.0'],
+            include_dirs = [hidapi_include, '/usr/include/libusb-1.0', '/usr/pkg/include/libusb-1.0'],
             libraries = ['usb-1.0'],
         )
     ]
