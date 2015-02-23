$NetBSD: patch-Source_WebCore_Target.pri,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

* Build libWebCore with libtool
* Install libWebCore libraries

--- src/qt/qtwebkit/Source/WebCore/Target.pri.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/WebCore/Target.pri
@@ -13,6 +13,8 @@ WEBKIT += wtf
 WEBKIT += javascriptcore
 
 CONFIG += staticlib
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 # Do it in the WebCore static lib to support force_static_libs_as_shared
 # since the QtWebKitWidgets lib wouldn't load QtWebKit in that case.
