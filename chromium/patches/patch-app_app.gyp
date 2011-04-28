$NetBSD: patch-app_app.gyp,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- app/app.gyp.orig	2011-04-13 08:01:07.000000000 +0000
+++ app/app.gyp
@@ -65,7 +65,7 @@
         '..',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'sources': [
             '../ui/base/dragdrop/gtk_dnd_util_unittest.cc',
           ],
@@ -82,7 +82,7 @@
             'win_util_unittest.cc',
           ],
         }],
-        ['OS =="linux" or OS =="freebsd"', {
+        ['OS =="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -166,7 +166,7 @@
     },
   ],
   'conditions': [
-    ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+    ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
       'targets': [{
         'target_name': 'app_unittest_strings',
         'type': 'none',
