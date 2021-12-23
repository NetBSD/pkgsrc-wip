$NetBSD$

Add a NetBSD entry to the Platform enum.
Undef a NetBSD macro that's coming in from somewhere.

--- src/libslic3r/Platform.hpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/libslic3r/Platform.hpp
@@ -3,6 +3,10 @@
 
 #include <string>
 
+#ifdef NetBSD
+#undef NetBSD
+#endif
+
 namespace Slic3r {
 
 enum class Platform
@@ -25,6 +29,7 @@ enum class PlatformFlavor
     WSL,             // Microsoft's Windows on Linux (Linux kernel simulated on NTFS kernel)
     WSL2,            // Microsoft's Windows on Linux, version 2 (virtual machine)
     OpenBSD,         // For Platform::BSDUnix
+    NetBSD,
     GenericOSX,      // For Platform::OSX
     OSXOnX86,        // For Apple's on Intel X86 CPU
     OSXOnArm,        // For Apple's on Arm CPU
