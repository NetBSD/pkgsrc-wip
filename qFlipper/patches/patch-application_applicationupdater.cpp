$NetBSD$

Disable self-updates -- updates are in pkgsrc's jurisdiction.  Fixes
build on non-Windows/macOS/Linux too.

--- application/applicationupdater.cpp.orig	2023-11-10 09:40:31.000000000 +0000
+++ application/applicationupdater.cpp
@@ -63,6 +63,11 @@ bool ApplicationUpdater::canUpdate(const
 
 void ApplicationUpdater::installUpdate(const Flipper::Updates::VersionInfo &versionInfo)
 {
+#if 1
+    qCWarning(CATEGORY_SELFUPDATES).noquote() << "Self-updates not supported; update package instead";
+    setState(ErrorOccured);
+    return;
+#else
 #ifdef Q_OS_WINDOWS
     const auto fileInfo = versionInfo.fileInfo(QStringLiteral("installer"), QStringLiteral("windows/amd64"));
 #elif defined(Q_OS_MAC)
@@ -151,6 +156,7 @@ void ApplicationUpdater::installUpdate(c
         qCWarning(CATEGORY_SELFUPDATES) << "Downloading the application update package...";
         setState(Downloading);
     }
+#endif
 }
 
 void ApplicationUpdater::setState(ApplicationUpdater::State state)
@@ -175,6 +181,9 @@ void ApplicationUpdater::setProgress(dou
 
 bool ApplicationUpdater::performUpdate(const QString &path)
 {
+#if 1
+    return false;
+#else
     const auto exitApplication = []() {
         qCInfo(CATEGORY_SELFUPDATES) << "Update started, exiting the application...";
         QCoreApplication::exit(0);
@@ -213,4 +222,5 @@ bool ApplicationUpdater::performUpdate(c
 #else
 #error "Unsupported OS"
 #endif
+#endif
 }
