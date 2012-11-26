$NetBSD: patch-src_plugins_coreplugin_coreplugin.pro,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Add a separate $PREFIX to the install paths, as qmake only supports
a single $INSTALL_ROOT prefix. By setting $INSTALL_ROOT to $DESTDIR
this enables DESTDIR support and fixes the library paths.

--- src/plugins/coreplugin/coreplugin.pro.orig	2012-08-08 13:47:06.000000000 +0000
+++ src/plugins/coreplugin/coreplugin.pro
@@ -223,7 +223,7 @@ else:unix {
 
     for(imagesize, IMAGE_SIZE_LIST) {
         eval(image$${imagesize}.files = images/logo/$${imagesize}/qtcreator.png)
-        eval(image$${imagesize}.path = /share/icons/hicolor/$${imagesize}x$${imagesize}/apps)
+        eval(image$${imagesize}.path = $$(PREFIX)/share/icons/hicolor/$${imagesize}x$${imagesize}/apps)
         INSTALLS += image$${imagesize}
     }
 }
