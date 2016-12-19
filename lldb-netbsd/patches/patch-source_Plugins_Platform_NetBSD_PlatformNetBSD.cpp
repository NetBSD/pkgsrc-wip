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
 
@@ -127,20 +156,19 @@ Error PlatformNetBSD::RunShellCommand(co
 }
 
 Error PlatformNetBSD::ResolveExecutable(
-    const ModuleSpec &module_spec, lldb::ModuleSP &exe_module_sp,
+    const ModuleSpec &ms, lldb::ModuleSP &exe_module_sp,
     const FileSpecList *module_search_paths_ptr) {
   Error error;
   // Nothing special to do here, just use the actual file and architecture
 
   char exe_path[PATH_MAX];
-  ModuleSpec resolved_module_spec(module_spec);
+  ModuleSpec resolved_module_spec(ms);
 
   if (IsHost()) {
-    // If we have "ls" as the module_spec's file, resolve the executable
-    // location based on
+    // If we have "ls" as the exe_file, resolve the executable location based on
     // the current path variables
     if (!resolved_module_spec.GetFileSpec().Exists()) {
-      module_spec.GetFileSpec().GetPath(exe_path, sizeof(exe_path));
+      resolved_module_spec.GetFileSpec().GetPath(exe_path, sizeof(exe_path));
       resolved_module_spec.GetFileSpec().SetFile(exe_path, true);
     }
 
@@ -163,24 +191,46 @@ Error PlatformNetBSD::ResolveExecutable(
       // We may connect to a process and use the provided executable (Don't use
       // local $PATH).
 
-      // Resolve any executable within a bundle on MacOSX
-      Host::ResolveExecutableInBundle(resolved_module_spec.GetFileSpec());
-
-      if (resolved_module_spec.GetFileSpec().Exists()) {
+      if (resolved_module_spec.GetFileSpec().Exists())
         error.Clear();
-      } else {
-        error.SetErrorStringWithFormat(
-            "the platform is not currently connected, and '%s' doesn't exist "
-            "in the system root.",
-            resolved_module_spec.GetFileSpec().GetPath().c_str());
-      }
+      else
+        error.SetErrorStringWithFormat("the platform is not currently "
+                                       "connected, and '%s' doesn't exist in "
+                                       "the system root.",
+                                       exe_path);
     }
   }
 
   if (error.Success()) {
     if (resolved_module_spec.GetArchitecture().IsValid()) {
       error = ModuleList::GetSharedModule(resolved_module_spec, exe_module_sp,
-                                          module_search_paths_ptr, NULL, NULL);
+                                          NULL, NULL, NULL);
+      if (error.Fail()) {
+        // If we failed, it may be because the vendor and os aren't known. If
+        // that is the
+        // case, try setting them to the host architecture and give it another
+        // try.
+        llvm::Triple &module_triple =
+            resolved_module_spec.GetArchitecture().GetTriple();
+        bool is_vendor_specified =
+            (module_triple.getVendor() != llvm::Triple::UnknownVendor);
+        bool is_os_specified =
+            (module_triple.getOS() != llvm::Triple::UnknownOS);
+        if (!is_vendor_specified || !is_os_specified) {
+          const llvm::Triple &host_triple =
+              HostInfo::GetArchitecture(HostInfo::eArchKindDefault).GetTriple();
+
+          if (!is_vendor_specified)
+            module_triple.setVendorName(host_triple.getVendorName());
+          if (!is_os_specified)
+            module_triple.setOSName(host_triple.getOSName());
+
+          error = ModuleList::GetSharedModule(resolved_module_spec,
+                                              exe_module_sp, NULL, NULL, NULL);
+        }
+      }
+
+      // TODO find out why exe_module_sp might be NULL
 
       if (!exe_module_sp || exe_module_sp->GetObjectFile() == NULL) {
         exe_module_sp.reset();
@@ -199,7 +249,7 @@ Error PlatformNetBSD::ResolveExecutable(
            ++idx) {
         error =
             ModuleList::GetSharedModule(resolved_module_spec, exe_module_sp,
-                                        module_search_paths_ptr, NULL, NULL);
+                                        NULL, NULL, NULL);
         // Did we find an executable using one of the
         if (error.Success()) {
           if (exe_module_sp && exe_module_sp->GetObjectFile())
@@ -234,8 +284,8 @@ Error PlatformNetBSD::ResolveExecutable(
 
 // From PlatformMacOSX only
 Error PlatformNetBSD::GetFileWithUUID(const FileSpec &platform_file,
-                                      const UUID *uuid_ptr,
-                                      FileSpec &local_file) {
+                                     const UUID *uuid_ptr,
+                                     FileSpec &local_file) {
   if (IsRemote()) {
     if (m_remote_platform_sp)
       return m_remote_platform_sp->GetFileWithUUID(platform_file, uuid_ptr,
