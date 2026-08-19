$NetBSD$

Replace ranges::fold_left with std::accumulate — range-v3 0.10.0
(pkgsrc version) does not have fold_left, added in range-v3 0.12.0.

--- Telegram/SourceFiles/platform/linux/notifications_manager_linux.cpp.orig	2026-08-03 10:32:05.664801354 +0300
+++ Telegram/SourceFiles/platform/linux/notifications_manager_linux.cpp	2026-08-03 10:32:05.711070649 +0300
@@ -28,6 +28,7 @@
 
 #include <QtCore/QBuffer>
 #include <QtCore/QVersionNumber>
+#include <numeric>
 #include <QtGui/QGuiApplication>
 
 #include <ksandbox.h>
@@ -363,9 +364,10 @@
 
 	if (!CurrentCapabilities.empty()) {
 		LOG(("Notification daemon capabilities: %1").arg(
-			ranges::fold_left(
-				CurrentCapabilities,
-				"",
+			std::accumulate(
+				CurrentCapabilities.begin(),
+				CurrentCapabilities.end(),
+				std::string(),
 				[](const std::string &a, const std::string &b) {
 					return a + (a.empty() ? "" : ", ") + b;
 				}).c_str()));
