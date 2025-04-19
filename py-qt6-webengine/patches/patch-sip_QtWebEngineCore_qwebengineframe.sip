$NetBSD$

https://crux.nu/ports/crux-3.7/contrib/python3-pyqt6-webengine/pyqt6-webengine-fix-build.patch

--- sip/QtWebEngineCore/qwebengineframe.sip.orig	2024-12-06 14:49:43.838095400 +0000
+++ sip/QtWebEngineCore/qwebengineframe.sip
@@ -25,6 +25,7 @@
 class QWebEngineFrame /NoDefaultCtors/
 {
 %TypeHeaderCode
+#include <qvariant.h>
 #include <qwebengineframe.h>
 %End
 
