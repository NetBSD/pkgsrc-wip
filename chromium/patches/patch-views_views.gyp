$NetBSD: patch-views_views.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- views/views.gyp.orig	2011-04-13 08:01:32.000000000 +0000
+++ views/views.gyp
@@ -8,7 +8,7 @@
   },
 
   'conditions': [
-    [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+    [ 'OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
       'conditions': [
         ['sysroot!=""', {
           'variables': {
@@ -29,7 +29,7 @@
       ['exclude', '/(gtk|win|x11)_[^/]*\\.cc$'],
     ],
     'conditions': [
-      ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {'sources/': [
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {'sources/': [
         ['include', '/gtk/'],
         ['include', '_(gtk|linux|posix|skia|x)\\.cc$'],
         ['include', '/(gtk|x11)_[^/]*\\.cc$'],
@@ -371,7 +371,7 @@
         '<(DEPTH)/third_party/wtl/include',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:x11',
@@ -472,7 +472,7 @@
         '<(SHARED_INTERMEDIATE_DIR)/app/app_resources/app_resources.rc',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../chrome/chrome.gyp:packed_resources',
@@ -544,7 +544,7 @@
         '<(SHARED_INTERMEDIATE_DIR)/app/app_resources/app_resources.rc',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../chrome/chrome.gyp:packed_resources',
