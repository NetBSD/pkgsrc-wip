$NetBSD$

--- ../llvm/tools/lldb/source/Initialization/SystemInitializerCommon.cpp.orig	2015-11-18 04:51:19.000000000 +0000
+++ ../llvm/tools/lldb/source/Initialization/SystemInitializerCommon.cpp
@@ -115,6 +115,7 @@ SystemInitializerCommon::Initialize()
     DynamicLoaderWindowsDYLD::Initialize();
     platform_freebsd::PlatformFreeBSD::Initialize();
     platform_linux::PlatformLinux::Initialize();
+    platform_netbsd::PlatformNetBSD::Initialize();
     PlatformWindows::Initialize();
     PlatformKalimba::Initialize();
     platform_android::PlatformAndroid::Initialize();
@@ -162,6 +163,7 @@ SystemInitializerCommon::Terminate()
     DynamicLoaderWindowsDYLD::Terminate();
     platform_freebsd::PlatformFreeBSD::Terminate();
     platform_linux::PlatformLinux::Terminate();
+    platform_netbsd::PlatformNetBSD::Terminate();
     PlatformWindows::Terminate();
     PlatformKalimba::Terminate();
     platform_android::PlatformAndroid::Terminate();
