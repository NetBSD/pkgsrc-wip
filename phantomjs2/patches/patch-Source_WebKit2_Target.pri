$NetBSD: patch-Source_WebKit2_Target.pri,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

* Fix build from the lack of many headers, this is ugly hack
* Build libWebKit2 with libtool
* Install libWebKit2 libraries

--- src/qt/qtwebkit/Source/WebKit2/Target.pri.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/WebKit2/Target.pri
@@ -7,12 +7,17 @@
 TEMPLATE = lib
 TARGET = WebKit2
 
+QMAKE_EXTRA_TARGETS += fwheader_generator
+
 include(WebKit2.pri)
 
 WEBKIT += wtf javascriptcore webcore
 
 CONFIG += staticlib
 
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
+
 RESOURCES += $$PWD/WebKit2.qrc
 
 enable?(netscape_plugin_api):enable?(plugin_architecture_unsupported) {
