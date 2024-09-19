$NetBSD: patch-src_qt_src_3rdparty_webkit_Source_WebKit_qt_WebCoreSupport_InspectorServerQt.cpp,v 1.1 2013/06/18 11:02:23 fhajny Exp $

Fix build with GCC 4.7.
--- src/qt/src/3rdparty/webkit/Source/WebKit/qt/WebCoreSupport/InspectorServerQt.cpp.orig	2013-06-03 23:11:50.000000000 +0000
+++ src/qt/src/3rdparty/webkit/Source/WebKit/qt/WebCoreSupport/InspectorServerQt.cpp
@@ -289,7 +289,7 @@ int InspectorServerRequestHandlerQt::web
     m_tcpConnection->putChar(0x81);
     if (length <= 125)
         m_tcpConnection->putChar(static_cast<uint8_t>(length));
-    else if (length <= pow(2,16)) {
+    else if (length <= pow((float)2,16)) {
         m_tcpConnection->putChar(126);
         quint16 length16 = qToBigEndian<quint16>(static_cast<quint16>(length));
         m_tcpConnection->write(reinterpret_cast<char*>(&length16), 2);
