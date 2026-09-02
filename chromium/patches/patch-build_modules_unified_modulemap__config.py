$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- build/modules/unified/modulemap_config.py.orig	2026-08-31 22:47:51.000000000 +0000
+++ build/modules/unified/modulemap_config.py
@@ -63,7 +63,7 @@ class AllowedHeader(Header):
 
 
 def headers(os):
-  is_linux = os == 'linux'
+  is_linux = os == 'linux' or os == 'openbsd' or os == 'freebsd' or os == 'netbsd'
   is_android = os == 'android'
   is_ios = os == 'ios'
   is_mac = os == 'mac'
