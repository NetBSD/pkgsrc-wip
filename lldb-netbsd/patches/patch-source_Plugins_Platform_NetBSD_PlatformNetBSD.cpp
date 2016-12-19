$NetBSD$

--- source/Plugins/Platform/NetBSD/PlatformNetBSD.cpp.orig	2016-12-17 10:29:30.000000000 +0000
+++ source/Plugins/Platform/NetBSD/PlatformNetBSD.cpp
@@ -23,6 +23,7 @@
 #include "lldb/Breakpoint/BreakpointSite.h"
 #include "lldb/Core/Debugger.h"
 #include "lldb/Core/Error.h"
+#include "lldb/Core/Log.h"
 #include "lldb/Core/Module.h"
 #include "lldb/Core/ModuleSpec.h"
 #include "lldb/Core/PluginManager.h"
@@ -34,10 +35,29 @@ using namespace lldb;
 using namespace lldb_private;
 using namespace lldb_private::platform_netbsd;
 
+static uint32_t g_initialize_count = 0;
+
+//------------------------------------------------------------------
+/// Code to handle the PlatformNetBSD settings
+//------------------------------------------------------------------
+
+//------------------------------------------------------------------
+
 PlatformSP PlatformNetBSD::CreateInstance(bool force, const ArchSpec *arch) {
-  // The only time we create an instance is when we are creating a remote
-  // netbsd platform
-  const bool is_host = false;
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PLATFORM));
+  if (log) {
+    const char *arch_name;
+    if (arch && arch->GetArchitectureName())
+      arch_name = arch->GetArchitectureName();
+    else
+      arch_name = "<null>";
+
+    const char *triple_cstr =
+        arch ? arch->GetTriple().getTriple().c_str() : "<null>";
+
+    log->Printf("PlatformNetBSD::%s(force=%s, arch={%s,%s})", __FUNCTION__,
+                force ? "true" : "false", arch_name, triple_cstr);
+  }
 
   bool create = force;
   if (create == false && arch && arch->IsValid()) {
@@ -51,8 +71,19 @@ PlatformSP PlatformNetBSD::CreateInstanc
       break;
     }
   }
-  if (create)
-    return PlatformSP(new PlatformNetBSD(is_host));
+
+  if (create) {
+    if (log)
+      log->Printf("PlatformNetBSD::%s() creating remote-netbsd platform",
+                  __FUNCTION__);
+    return PlatformSP(new PlatformNetBSD(false));
+  }
+
+  if (log)
+    log->Printf(
+        "PlatformLinux::%s() aborting creation of remote-netbsd platform",
+        __FUNCTION__);
+
   return PlatformSP();
 }
 
@@ -73,8 +104,6 @@ const char *PlatformNetBSD::GetDescripti
     return "Remote NetBSD user platform plug-in.";
 }
 
-static uint32_t g_initialize_count = 0;
-
 void PlatformNetBSD::Initialize() {
   Platform::Initialize();
 
