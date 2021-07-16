$NetBSD$

Add a NetBSD entry to the Platform enum.
Undef a NetBSD macro that's coming in from somewhere.

--- src/libslic3r/Platform.hpp.orig	2021-07-08 06:46:36.000000000 +0000
+++ src/libslic3r/Platform.hpp
@@ -1,6 +1,8 @@
 #ifndef SLIC3R_Platform_HPP
 #define SLIC3R_Platform_HPP
 
+#undef NetBSD
+
 namespace Slic3r {
 
 enum class Platform
@@ -28,6 +30,7 @@ enum class PlatformFlavor
 	WSL2,
 	// For Platform::BSDUnix
 	OpenBSD,
+	NetBSD,
 };
 
 // To be called on program start-up.
