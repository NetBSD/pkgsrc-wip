$NetBSD$

--- source/Plugins/Platform/NetBSD/PlatformNetBSD.cpp.orig	2016-12-17 10:29:30.000000000 +0000
+++ source/Plugins/Platform/NetBSD/PlatformNetBSD.cpp
@@ -34,6 +34,12 @@ using namespace lldb;
 using namespace lldb_private;
 using namespace lldb_private::platform_netbsd;
 
+static uint32_t g_initialize_count = 0;
+
+//------------------------------------------------------------------
+/// Code to handle the PlatformNetBSD settings
+//------------------------------------------------------------------
+
 PlatformSP PlatformNetBSD::CreateInstance(bool force, const ArchSpec *arch) {
   // The only time we create an instance is when we are creating a remote
   // netbsd platform
@@ -73,8 +79,6 @@ const char *PlatformNetBSD::GetDescripti
     return "Remote NetBSD user platform plug-in.";
 }
 
-static uint32_t g_initialize_count = 0;
-
 void PlatformNetBSD::Initialize() {
   Platform::Initialize();
 
