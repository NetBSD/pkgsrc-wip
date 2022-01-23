$NetBSD$

* Fix typo, fixes crash on NetBSD and possibly other platforms

--- src/userCmds.cpp.orig	2022-01-23 20:53:11.898537636 +0000
+++ src/userCmds.cpp
@@ -462,9 +462,9 @@ void loadShellMenuYaml(std::vector<MenuD
 #elif defined(Q_OS_FREEBSD)
 			static QByteArray defaultMenu = loadResource(QLatin1String("DefaultShellMenuFreeBSD.yaml"));
 #elif defined(Q_OS_UNIX)
-			static QByteArray defaultMenu = loadResource(QLatin1String("DefaultShellUnix.yaml"));
+			static QByteArray defaultMenu = loadResource(QLatin1String("DefaultShellMenuUnix.yaml"));
 #elif defined(Q_OS_WIN)
-			static QByteArray defaultMenu = loadResource(QLatin1String("DefaultShellWindows.yaml"));
+			static QByteArray defaultMenu = loadResource(QLatin1String("DefaultShellMenuWindows.yaml"));
 #endif
 			menu = YAML::LoadAll(defaultMenu.data());
 		}
