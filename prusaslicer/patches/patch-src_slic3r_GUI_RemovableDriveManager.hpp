$NetBSD$

Migrate away from features deprecated in tbb 2021.3.
Adapted from upstream git commit e13535f822b5efe0e3b471bc366e8d3ea96059d5.

--- src/slic3r/GUI/RemovableDriveManager.hpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/slic3r/GUI/RemovableDriveManager.hpp
@@ -5,7 +5,7 @@
 #include <string>
 
 #include <boost/thread.hpp>
-#include <tbb/mutex.h>
+#include <mutex>
 #include <condition_variable>
 
 // Custom wxWidget events
@@ -111,9 +111,9 @@ private:
 	// m_current_drives is guarded by m_drives_mutex
 	// sorted ascending by path
 	std::vector<DriveData> 	m_current_drives;
-	mutable tbb::mutex 		m_drives_mutex;
+	mutable std::mutex 		m_drives_mutex;
 	// Locking the update() function to avoid that the function is executed multiple times.
-	mutable tbb::mutex 		m_inside_update_mutex;
+	mutable std::mutex 		m_inside_update_mutex;
 
 	// Returns drive path (same as path in DriveData) if exists otherwise empty string.
 	std::string 			get_removable_drive_from_path(const std::string& path);
