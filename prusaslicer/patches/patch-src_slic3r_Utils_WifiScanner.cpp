$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/Utils/WifiScanner.cpp.orig	2023-11-23 14:51:47.000000000 +0000
+++ src/slic3r/Utils/WifiScanner.cpp
@@ -19,7 +19,7 @@
 #include "WifiScannerMac.h"
 #endif 
 
-#if __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #include <dbus/dbus.h> /* Pull in all of D-Bus headers. */
 #endif //__linux__
 
@@ -457,4 +457,4 @@ std::string WifiScanner::get_psk(const s
     }
     return {};
 }
-} // Slic3r
\ No newline at end of file
+} // Slic3r
