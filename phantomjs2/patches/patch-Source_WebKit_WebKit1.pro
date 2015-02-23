$NetBSD: patch-Source_WebKit_WebKit1.pro,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

* Build libWebKit libraries with libtool
* Install libWebKit libraries

--- src/qt/qtwebkit/Source/WebKit/WebKit1.pro.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/WebKit/WebKit1.pro
@@ -18,6 +18,9 @@ DEFINES += QT_BUILD_WEBKIT_LIB
 
 CONFIG += staticlib
 
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
+
 SOURCES += \
     $$PWD/qt/Api/qhttpheader.cpp \
     $$PWD/qt/Api/qwebdatabase.cpp \
