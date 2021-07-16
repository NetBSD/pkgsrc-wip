$NetBSD$

Add platform flavour NetBSD.

--- src/libslic3r/Platform.cpp.orig	2021-07-08 06:46:36.000000000 +0000
+++ src/libslic3r/Platform.cpp
@@ -49,6 +49,10 @@ void detect_platform()
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
