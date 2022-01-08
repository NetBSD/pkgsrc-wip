$NetBSD$

Include netbsd conditional.

--- src/calibre/constants.py.orig	2021-12-17 00:40:19.000000000 +0000
+++ src/calibre/constants.py
@@ -256,7 +256,7 @@ class ExtensionsImporter:
             extra = ('winutil', 'wpd', 'winfonts', 'winsapi')
         elif ismacos:
             extra = ('usbobserver', 'cocoa', 'libusb', 'libmtp')
-        elif isfreebsd or ishaiku or islinux:
+        elif isfreebsd or ishaiku or islinux or isnetbsd:
             extra = ('libusb', 'libmtp')
         else:
             extra = ()
