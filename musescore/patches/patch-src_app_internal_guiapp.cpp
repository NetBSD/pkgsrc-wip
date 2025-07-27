$NetBSD$

Treat NetBSD like FreeBSD.

--- src/app/internal/guiapp.cpp.orig	2025-07-21 11:27:25.085180317 +0000
+++ src/app/internal/guiapp.cpp
@@ -178,7 +178,7 @@ void GuiApp::perform()
     const QString mainQmlFile = "/platform/win/Main.qml";
 #elif defined(Q_OS_MACOS)
     const QString mainQmlFile = "/platform/mac/Main.qml";
-#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     const QString mainQmlFile = "/platform/linux/Main.qml";
 #elif defined(Q_OS_WASM)
     const QString mainQmlFile = "/Main.wasm.qml";
