$NetBSD$

Fix build with Qt5>=5.14

--- daemon/core.cpp.orig	2019-10-16 15:17:40.000000000 +0000
+++ daemon/core.cpp
@@ -30,6 +30,7 @@
 #include <QScopedArrayPointer>
 #include <QSettings>
 #include <QStandardPaths>
+#include <QFile>
 #include <QTimer>
 #include <QDBusConnectionInterface>
 #include <QDBusServiceWatcher>
