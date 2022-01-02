$NetBSD$

use install prefix

--- app/app.pro.orig	2020-03-08 19:20:59.000000000 +0000
+++ app/app.pro
@@ -370,7 +370,7 @@ RESOURCES += \
 # See http://doc.qt.io/qt-5/qmake-advanced-usage.html
 
 binfile.files += mindforger
-binfile.path = /usr/bin/
+binfile.path = $$(PREFIX)/bin/
 INSTALLS += binfile
 
 # ########################################
