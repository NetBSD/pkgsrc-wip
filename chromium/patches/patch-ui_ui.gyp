$NetBSD: patch-ui_ui.gyp,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- ui/ui.gyp.orig	2011-05-24 08:01:59.000000000 +0000
+++ ui/ui.gyp
@@ -13,7 +13,7 @@
       ['exclude', '/(gtk|win|x11)_[^/]*\\.cc$'],
     ],
     'conditions': [
-      ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {'sources/': [
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {'sources/': [
         ['include', '/gtk/'],
         ['include', '_(gtk|linux|posix|skia|x)\\.cc$'],
         ['include', '/(gtk|x11)_[^/]*\\.cc$'],
