$NetBSD: patch-src_phantomjs.pro,v 1.1 2013/06/18 11:02:23 fhajny Exp $

Fix plugin linking.
--- src/phantomjs.pro.orig	2013-06-03 23:11:50.000000000 +0000
+++ src/phantomjs.pro
@@ -131,3 +131,21 @@ win32-msvc* {
             qico
     }
 }
+
+solaris* {
+    LIBS += -lnsl -lsocket
+
+    QTPLUGIN += \
+    qcncodecs \
+    qjpcodecs \
+    qkrcodecs \
+    qtwcodecs
+}
+
+netbsd* {
+    QTPLUGIN += \
+    qcncodecs \
+    qjpcodecs \
+    qkrcodecs \
+    qtwcodecs
+}
