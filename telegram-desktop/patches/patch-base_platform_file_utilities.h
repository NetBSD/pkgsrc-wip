$NetBSD$

--- Telegram/lib_base/base/platform/base_platform_file_utilities.h.orig	2020-01-21 15:35:25.000000000 +0000
+++ Telegram/lib_base/base/platform/base_platform_file_utilities.h
@@ -22,7 +22,7 @@ void RemoveQuarantine(const QString &pat
 
 #ifdef Q_OS_MAC
 #include "base/platform/mac/base_file_utilities_mac.h"
-#elif defined Q_OS_LINUX // Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_NETBSD // Q_OS_MAC
 #include "base/platform/linux/base_file_utilities_linux.h"
 #elif defined Q_OS_WINRT || defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX
 #include "base/platform/win/base_file_utilities_win.h"
