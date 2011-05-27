$NetBSD: patch-ui_views_views.gyp,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- ui/views/views.gyp.orig	2011-05-24 08:01:59.000000000 +0000
+++ ui/views/views.gyp
@@ -13,7 +13,7 @@
       ['exclude', '/(gtk|win|x11)_[^/]*\\.cc$'],
     ],
     'conditions': [
-      ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {'sources/': [
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {'sources/': [
         ['include', '/gtk/'],
         ['include', '_(gtk|linux|posix|skia|x)\\.cc$'],
         ['include', '/(gtk|x11)_[^/]*\\.cc$'],
@@ -98,7 +98,7 @@
         '<(DEPTH)',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '<(DEPTH)/build/linux/system.gyp:gtk',
             '<(DEPTH)/build/linux/system.gyp:x11',
@@ -141,7 +141,7 @@
         '<(DEPTH)',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '<(DEPTH)/build/linux/system.gyp:gtk',
             '<(DEPTH)/chrome/chrome.gyp:packed_resources',
