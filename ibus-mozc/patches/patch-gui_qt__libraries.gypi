$NetBSD: patch-gui_qt__libraries.gypi,v 1.1 2013/01/15 11:29:02 ryo-on Exp $

--- gui/qt_libraries.gypi.orig	2012-08-31 05:36:43.000000000 +0000
+++ gui/qt_libraries.gypi
@@ -84,7 +84,7 @@
         '$(SDKROOT)/System/Library/Frameworks/Carbon.framework',
       ]
     }],
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="netbsd"', {
       'conditions': [
         ['qt_dir', {
           'libraries': [
