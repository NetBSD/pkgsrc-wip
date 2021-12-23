$NetBSD$

Add platform flavour NetBSD.

--- src/libslic3r/Platform.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/libslic3r/Platform.cpp
@@ -86,6 +86,10 @@ void detect_platform()
     BOOST_LOG_TRIVIAL(info) << "Platform: OpenBSD";
 	s_platform 		  = Platform::BSDUnix;
 	s_platform_flavor = PlatformFlavor::OpenBSD;
+#elif defined(__NetBSD__)
+    BOOST_LOG_TRIVIAL(info) << "Platform: NetBSD";
+	s_platform 		  = Platform::BSDUnix;
+	s_platform_flavor = PlatformFlavor::NetBSD;
 #else
 	// This should not happen.
     BOOST_LOG_TRIVIAL(info) << "Platform: Unknown";
@@ -134,6 +138,7 @@ std::string platform_flavor_to_string(Pl
         case PlatformFlavor::WSL             : return "WSL";
         case PlatformFlavor::WSL2            : return "WSL2";
         case PlatformFlavor::OpenBSD         : return "OpenBSD";
+        case PlatformFlavor::NetBSD          : return "NetBSD";
         case PlatformFlavor::GenericOSX      : return "GenericOSX";
         case PlatformFlavor::OSXOnX86        : return "OSXOnX86";
         case PlatformFlavor::OSXOnArm        : return "OSXOnArm";
