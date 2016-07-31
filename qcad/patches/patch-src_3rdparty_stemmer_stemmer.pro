$NetBSD$

--- src/3rdparty/stemmer/stemmer.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/3rdparty/stemmer/stemmer.pro
@@ -44,5 +44,5 @@ HEADERS += \

 TARGET = stemmer
 TEMPLATE = lib
-CONFIG += staticlib
-#CONFIG += plugin
+#CONFIG += staticlib
+CONFIG += plugin
