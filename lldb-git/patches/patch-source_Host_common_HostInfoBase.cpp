$NetBSD$

--- source/Host/common/HostInfoBase.cpp.orig	2017-02-02 23:56:41.000000000 +0000
+++ source/Host/common/HostInfoBase.cpp
@@ -22,9 +22,10 @@
 #include "llvm/Support/Host.h"
 #include "llvm/Support/Path.h"
 #include "llvm/Support/ScopedPrinter.h"
+#include "llvm/Support/Threading.h"
 #include "llvm/Support/raw_ostream.h"
 
-#include <mutex> // std::once
+#include <mutex>
 #include <thread>
 
 using namespace lldb;
@@ -79,8 +80,8 @@ void HostInfoBase::Terminate() {
 }
 
 uint32_t HostInfoBase::GetNumberCPUS() {
-  static std::once_flag g_once_flag;
-  std::call_once(g_once_flag, []() {
+  static llvm::once_flag g_once_flag;
+  llvm::call_once(g_once_flag, []() {
     g_fields->m_number_cpus = std::thread::hardware_concurrency();
   });
   return g_fields->m_number_cpus;
@@ -89,8 +90,8 @@ uint32_t HostInfoBase::GetNumberCPUS() {
 uint32_t HostInfoBase::GetMaxThreadNameLength() { return 0; }
 
 llvm::StringRef HostInfoBase::GetVendorString() {
-  static std::once_flag g_once_flag;
-  std::call_once(g_once_flag, []() {
+  static llvm::once_flag g_once_flag;
+  llvm::call_once(g_once_flag, []() {
     g_fields->m_vendor_string =
         HostInfo::GetArchitecture().GetTriple().getVendorName().str();
   });
@@ -98,8 +99,8 @@ llvm::StringRef HostInfoBase::GetVendorS
 }
 
 llvm::StringRef HostInfoBase::GetOSString() {
-  static std::once_flag g_once_flag;
-  std::call_once(g_once_flag, []() {
+  static llvm::once_flag g_once_flag;
+  llvm::call_once(g_once_flag, []() {
     g_fields->m_os_string =
         std::move(HostInfo::GetArchitecture().GetTriple().getOSName());
   });
@@ -107,8 +108,8 @@ llvm::StringRef HostInfoBase::GetOSStrin
 }
 
 llvm::StringRef HostInfoBase::GetTargetTriple() {
-  static std::once_flag g_once_flag;
-  std::call_once(g_once_flag, []() {
+  static llvm::once_flag g_once_flag;
+  llvm::call_once(g_once_flag, []() {
     g_fields->m_host_triple =
         HostInfo::GetArchitecture().GetTriple().getTriple();
   });
@@ -116,8 +117,8 @@ llvm::StringRef HostInfoBase::GetTargetT
 }
 
 const ArchSpec &HostInfoBase::GetArchitecture(ArchitectureKind arch_kind) {
-  static std::once_flag g_once_flag;
-  std::call_once(g_once_flag, []() {
+  static llvm::once_flag g_once_flag;
+  llvm::call_once(g_once_flag, []() {
     HostInfo::ComputeHostArchitectureSupport(g_fields->m_host_arch_32,
                                              g_fields->m_host_arch_64);
   });
@@ -144,9 +145,9 @@ bool HostInfoBase::GetLLDBPath(lldb::Pat
   FileSpec *result = nullptr;
   switch (type) {
   case lldb::ePathTypeLLDBShlibDir: {
-    static std::once_flag g_once_flag;
+    static llvm::once_flag g_once_flag;
     static bool success = false;
-    std::call_once(g_once_flag, []() {
+    llvm::call_once(g_once_flag, []() {
       success =
           HostInfo::ComputeSharedLibraryDirectory(g_fields->m_lldb_so_dir);
       Log *log = lldb_private::GetLogIfAllCategoriesSet(LIBLLDB_LOG_HOST);
@@ -158,9 +159,9 @@ bool HostInfoBase::GetLLDBPath(lldb::Pat
       result = &g_fields->m_lldb_so_dir;
   } break;
   case lldb::ePathTypeSupportExecutableDir: {
-    static std::once_flag g_once_flag;
+    static llvm::once_flag g_once_flag;
     static bool success = false;
-    std::call_once(g_once_flag, []() {
+    llvm::call_once(g_once_flag, []() {
       success = HostInfo::ComputeSupportExeDirectory(
           g_fields->m_lldb_support_exe_dir);
       Log *log = lldb_private::GetLogIfAllCategoriesSet(LIBLLDB_LOG_HOST);
@@ -173,9 +174,9 @@ bool HostInfoBase::GetLLDBPath(lldb::Pat
       result = &g_fields->m_lldb_support_exe_dir;
   } break;
   case lldb::ePathTypeHeaderDir: {
-    static std::once_flag g_once_flag;
+    static llvm::once_flag g_once_flag;
     static bool success = false;
-    std::call_once(g_once_flag, []() {
+    llvm::call_once(g_once_flag, []() {
       success = HostInfo::ComputeHeaderDirectory(g_fields->m_lldb_headers_dir);
       Log *log = lldb_private::GetLogIfAllCategoriesSet(LIBLLDB_LOG_HOST);
       if (log)
@@ -186,9 +187,9 @@ bool HostInfoBase::GetLLDBPath(lldb::Pat
       result = &g_fields->m_lldb_headers_dir;
   } break;
   case lldb::ePathTypePythonDir: {
-    static std::once_flag g_once_flag;
+    static llvm::once_flag g_once_flag;
     static bool success = false;
-    std::call_once(g_once_flag, []() {
+    llvm::call_once(g_once_flag, []() {
       success = HostInfo::ComputePythonDirectory(g_fields->m_lldb_python_dir);
       Log *log = lldb_private::GetLogIfAllCategoriesSet(LIBLLDB_LOG_HOST);
       if (log)
@@ -199,9 +200,9 @@ bool HostInfoBase::GetLLDBPath(lldb::Pat
       result = &g_fields->m_lldb_python_dir;
   } break;
   case lldb::ePathTypeClangDir: {
-    static std::once_flag g_once_flag;
+    static llvm::once_flag g_once_flag;
     static bool success = false;
-    std::call_once(g_once_flag, []() {
+    llvm::call_once(g_once_flag, []() {
       success =
           HostInfo::ComputeClangDirectory(g_fields->m_lldb_clang_resource_dir);
       Log *log = lldb_private::GetLogIfAllCategoriesSet(LIBLLDB_LOG_HOST);
@@ -214,9 +215,9 @@ bool HostInfoBase::GetLLDBPath(lldb::Pat
       result = &g_fields->m_lldb_clang_resource_dir;
   } break;
   case lldb::ePathTypeLLDBSystemPlugins: {
-    static std::once_flag g_once_flag;
+    static llvm::once_flag g_once_flag;
     static bool success = false;
-    std::call_once(g_once_flag, []() {
+    llvm::call_once(g_once_flag, []() {
       success = HostInfo::ComputeSystemPluginsDirectory(
           g_fields->m_lldb_system_plugin_dir);
       Log *log = lldb_private::GetLogIfAllCategoriesSet(LIBLLDB_LOG_HOST);
@@ -229,9 +230,9 @@ bool HostInfoBase::GetLLDBPath(lldb::Pat
       result = &g_fields->m_lldb_system_plugin_dir;
   } break;
   case lldb::ePathTypeLLDBUserPlugins: {
-    static std::once_flag g_once_flag;
+    static llvm::once_flag g_once_flag;
     static bool success = false;
-    std::call_once(g_once_flag, []() {
+    llvm::call_once(g_once_flag, []() {
       success = HostInfo::ComputeUserPluginsDirectory(
           g_fields->m_lldb_user_plugin_dir);
       Log *log = lldb_private::GetLogIfAllCategoriesSet(LIBLLDB_LOG_HOST);
@@ -244,9 +245,9 @@ bool HostInfoBase::GetLLDBPath(lldb::Pat
       result = &g_fields->m_lldb_user_plugin_dir;
   } break;
   case lldb::ePathTypeLLDBTempSystemDir: {
-    static std::once_flag g_once_flag;
+    static llvm::once_flag g_once_flag;
     static bool success = false;
-    std::call_once(g_once_flag, []() {
+    llvm::call_once(g_once_flag, []() {
       success = HostInfo::ComputeProcessTempFileDirectory(
           g_fields->m_lldb_process_tmp_dir);
       Log *log = lldb_private::GetLogIfAllCategoriesSet(LIBLLDB_LOG_HOST);
@@ -259,9 +260,9 @@ bool HostInfoBase::GetLLDBPath(lldb::Pat
       result = &g_fields->m_lldb_process_tmp_dir;
   } break;
   case lldb::ePathTypeGlobalLLDBTempSystemDir: {
-    static std::once_flag g_once_flag;
+    static llvm::once_flag g_once_flag;
     static bool success = false;
-    std::call_once(g_once_flag, []() {
+    llvm::call_once(g_once_flag, []() {
       success = HostInfo::ComputeGlobalTempFileDirectory(
           g_fields->m_lldb_global_tmp_dir);
       Log *log = lldb_private::GetLogIfAllCategoriesSet(LIBLLDB_LOG_HOST);
