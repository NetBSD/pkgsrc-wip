$NetBSD$

Add sleep support for *BSD

--- TheForceEngine/TFE_System/system.cpp.orig	2023-05-27 05:02:04.000000000 +0000
+++ TheForceEngine/TFE_System/system.cpp
@@ -232,7 +232,7 @@ namespace TFE_System
 	{
 		Sleep(sleepDeltaMS);
 	}
-#elif defined __linux__
+#elif defined __linux__ || defined __FreeBSD__ || defined __NetBSD__ || defined __OpenBSD__
 	void sleep(u32 sleepDeltaMS)
 	{
 		struct timespec ts = {0, 0};
