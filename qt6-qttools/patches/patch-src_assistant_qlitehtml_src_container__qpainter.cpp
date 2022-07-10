$NetBSD$

* fix build with litehtml 0.6

--- src/assistant/qlitehtml/src/container_qpainter.cpp.orig	2022-07-09 11:08:02.699425232 +0000
+++ src/assistant/qlitehtml/src/container_qpainter.cpp
@@ -558,7 +558,7 @@ void DocumentContainerPrivate::draw_text
     painter->drawText(toQRect(pos), 0, QString::fromUtf8(text));
 }
 
-int DocumentContainerPrivate::pt_to_px(int pt)
+int DocumentContainerPrivate::pt_to_px(int pt) const
 {
     // magic factor of 11/12 to account for differences to webengine/webkit
     return m_paintDevice->physicalDpiY() * pt * 11 / m_paintDevice->logicalDpiY() / 12;
