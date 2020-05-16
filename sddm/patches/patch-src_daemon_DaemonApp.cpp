$NetBSD$

ConsoleKit is not started by the init system, so try to do it here.

--- src/daemon/DaemonApp.cpp.orig	2019-03-31 07:59:59.000000000 +0000
+++ src/daemon/DaemonApp.cpp
@@ -28,6 +28,9 @@
 
 #include "MessageHandler.h"
 
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
+#include <QDBusConnectionInterface>
+#endif
 #include <QDebug>
 #include <QHostInfo>
 #include <QTimer>
@@ -49,6 +52,10 @@ namespace SDDM {
         // set testing parameter
         m_testing = (arguments().indexOf(QStringLiteral("--test-mode")) != -1);
 
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
+        QDBusConnection::systemBus().interface()->startService(QStringLiteral("org.freedesktop.ConsoleKit"));
+#endif
+
         // create display manager
         m_displayManager = new DisplayManager(this);
 
