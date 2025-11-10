$NetBSD: patch-src_calibre_constants.py,v 1.6 2022/01/20 19:03:07 rhialto Exp $

Include netbsd conditional.

--- src/calibre/constants.py.orig	2025-11-07 04:15:11.000000000 +0000
+++ src/calibre/constants.py
@@ -281,7 +281,7 @@ class ExtensionsImporter:
             extra = ('winutil', 'wpd', 'winfonts', 'wintoast')
         elif ismacos:
             extra = ('usbobserver', 'cocoa', 'libusb', 'libmtp')
-        elif isfreebsd or ishaiku or islinux:
+        elif isfreebsd or ishaiku or islinux or isnetbsd:
             extra = ('libusb', 'libmtp')
         else:
             extra = ()
