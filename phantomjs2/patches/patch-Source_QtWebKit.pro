$NetBSD: patch-Source_QtWebKit.pro,v 1.1 2015/02/23 16:11:06 leot1990 Exp $

* Make all libraries as shared
* Do not build examples

--- src/qt/qtwebkit/Source/QtWebKit.pro.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/QtWebKit.pro
@@ -39,8 +39,4 @@ build?(webkit1) {
         SUBDIRS += tests
     }
 
-    examples.file = WebKit/qt/examples/examples.pro
-    examples.CONFIG += no_default_target
-    examples.makefile = Makefile
-    SUBDIRS += examples
 }
