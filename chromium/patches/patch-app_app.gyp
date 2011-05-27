$NetBSD: patch-app_app.gyp,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- app/app.gyp.orig	2011-05-24 08:01:04.000000000 +0000
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
@@ -81,7 +81,7 @@
             '../ui/base/view_prop_unittest.cc',
           ],
         }],
-        ['OS =="linux" or OS =="freebsd"', {
+        ['OS =="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -165,7 +165,7 @@
     },
   ],
   'conditions': [
-    ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+    ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
       'targets': [{
         'target_name': 'app_unittest_strings',
         'type': 'none',
