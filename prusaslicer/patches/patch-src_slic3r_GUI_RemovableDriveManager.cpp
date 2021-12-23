$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/RemovableDriveManager.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/RemovableDriveManager.cpp
@@ -187,7 +187,7 @@ namespace search_for_drives_internal 
 		//confirms if the file is removable drive and adds it to vector
 
 		if (
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 			// Chromium mounts removable drives in a way that produces the same device ID.
 			platform_flavor() == PlatformFlavor::LinuxOnChromium ||
 #endif
