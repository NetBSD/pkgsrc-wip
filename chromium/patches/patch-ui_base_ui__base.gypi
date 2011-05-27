$NetBSD: patch-ui_base_ui__base.gypi,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- ui/base/ui_base.gypi.orig	2011-05-24 08:01:59.000000000 +0000
+++ ui/base/ui_base.gypi
@@ -13,7 +13,7 @@
       ['exclude', '/(gtk|win|x11)_[^/]*\\.cc$'],
     ],
     'conditions': [
-      ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {'sources/': [
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {'sources/': [
         ['include', '/gtk/'],
         ['include', '_(gtk|linux|posix|skia|x)\\.cc$'],
         ['include', '/(gtk|x11)_[^/]*\\.cc$'],
@@ -85,7 +85,7 @@
         'clipboard/scoped_clipboard_writer.h',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:x11',
