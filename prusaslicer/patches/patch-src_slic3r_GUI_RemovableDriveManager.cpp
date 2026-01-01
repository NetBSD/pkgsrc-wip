$NetBSD$

Treat NetBSD like Linux.

Fix boost 1.88 compatibility.
https://github.com/prusa3d/PrusaSlicer/issues/14534

--- src/slic3r/GUI/RemovableDriveManager.cpp.orig	2025-11-06 09:19:38.000000000 +0000
+++ src/slic3r/GUI/RemovableDriveManager.cpp
@@ -35,7 +35,7 @@
 #include <pwd.h>
 #include <boost/filesystem.hpp>
 #include <boost/system/error_code.hpp>
-#include <boost/process.hpp>
+#include <boost/process/v1.hpp>
 #endif
 
 namespace Slic3r {
@@ -743,7 +743,7 @@ namespace search_for_drives_internal 
 		//confirms if the file is removable drive and adds it to vector
 
 		if (
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 			// Chromium mounts removable drives in a way that produces the same device ID.
 			platform_flavor() == PlatformFlavor::LinuxOnChromium ||
 #endif
@@ -859,15 +859,15 @@ void RemovableDriveManager::eject_drive(
 		// but neither triggers "succesful safe removal messege"
 		
 		BOOST_LOG_TRIVIAL(info) << "Ejecting started";
-		boost::process::ipstream istd_err;
-    	boost::process::child child(
+		boost::process::v1::ipstream istd_err;
+    	boost::process::v1::child child(
 #if __APPLE__		
-			boost::process::search_path("diskutil"), "eject", correct_path.c_str(), (boost::process::std_out & boost::process::std_err) > istd_err);
+			boost::process::v1::search_path("diskutil"), "eject", correct_path.c_str(), (boost::process::v1::std_out & boost::process::v1::std_err) > istd_err);
 		//Another option how to eject at mac. Currently not working.
 		//used insted of system() command;
 		//this->eject_device(correct_path);
 #else
-    		boost::process::search_path("umount"), correct_path.c_str(), (boost::process::std_out & boost::process::std_err) > istd_err);
+    		boost::process::v1::search_path("umount"), correct_path.c_str(), (boost::process::v1::std_out & boost::process::v1::std_err) > istd_err);
 #endif
 		std::string line;
 		while (child.running() && std::getline(istd_err, line)) {
@@ -881,7 +881,7 @@ void RemovableDriveManager::eject_drive(
             // The wait call can fail, as it did in https://github.com/prusa3d/PrusaSlicer/issues/5507
             // It can happen even in cases where the eject is sucessful, but better report it as failed.
             // We did not find a way to reliably retrieve the exit code of the process.
-			BOOST_LOG_TRIVIAL(error) << "boost::process::child::wait() failed during Ejection. State of Ejection is unknown. Error code: " << ec.value();
+			BOOST_LOG_TRIVIAL(error) << "boost::process::v1::child::wait() failed during Ejection. State of Ejection is unknown. Error code: " << ec.value();
 		} else {
 			int err = child.exit_code();
 	    	if (err) {
