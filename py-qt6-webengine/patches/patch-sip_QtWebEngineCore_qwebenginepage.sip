$NetBSD$

https://crux.nu/ports/crux-3.7/contrib/python3-pyqt6-webengine/pyqt6-webengine-fix-build.patch

--- sip/QtWebEngineCore/qwebenginepage.sip.orig	2024-12-06 14:49:43.839698600 +0000
+++ sip/QtWebEngineCore/qwebenginepage.sip
@@ -23,6 +23,7 @@
 class QWebEnginePage : public QObject
 {
 %TypeHeaderCode
+#include <qvariant.h>
 #include <qwebenginepage.h>
 %End
 
