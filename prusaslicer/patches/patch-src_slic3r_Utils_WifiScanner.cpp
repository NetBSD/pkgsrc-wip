$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/Utils/WifiScanner.cpp.orig	2024-02-23 10:58:40.000000000 +0000
+++ src/slic3r/Utils/WifiScanner.cpp
@@ -17,7 +17,7 @@
 #include "WifiScannerMac.h"
 #endif 
 
-#if __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #include <dbus/dbus.h> /* Pull in all of D-Bus headers. */
 #endif //__linux__
 
