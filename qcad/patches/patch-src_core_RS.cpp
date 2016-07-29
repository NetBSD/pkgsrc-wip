$NetBSD$

fix hardcoded paths

--- src/core/RS.cpp.orig	2016-06-30 12:42:57.000000000 +0000
+++ src/core/RS.cpp
@@ -101,15 +101,9 @@ QStringList RS::getDirectoryList(const Q
         //local (application) directory has priority over other dirs:
         dirList.append(appDir + QDir::separator() + subDirectory);

- #ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_NETBSD) || defined(Q_OS_FREEBSD)
         QString appDirName = QSettings.applicationName();
-        // Redhat style:
-        dirList.append("/usr/share/" + appDirName + "/" + subDirectory);
-
-        // SuSE style:
-        dirList.append("/usr/X11R6/" + appDirName + "/" + subDirectory);
-
-        dirList.append("/usr/X11R6/share/" + appDirName + "/" + subDirectory);
+        dirList.append("@PREFIX@/lib/" + appDirName + "/" + subDirectory);
         dirList.append(QDir::homePath() + "/." + appDirName + "/" + subDirectory);
 #endif
