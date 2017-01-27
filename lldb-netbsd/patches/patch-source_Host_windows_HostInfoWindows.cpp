$NetBSD$

--- source/Host/windows/HostInfoWindows.cpp.orig	2016-12-17 10:30:35.000000000 +0000
+++ source/Host/windows/HostInfoWindows.cpp
@@ -21,6 +21,7 @@
 #include "llvm/Support/raw_ostream.h"
 
 using namespace lldb_private;
+using namespace llvm;
 
 FileSpec HostInfoWindows::m_program_filespec;
 
@@ -90,8 +91,8 @@ bool HostInfoWindows::GetHostname(std::s
 }
 
 FileSpec HostInfoWindows::GetProgramFileSpec() {
-  static std::once_flag g_once_flag;
-  std::call_once(g_once_flag, []() {
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
+  llvm::call_once(g_once_flag, []() {
     std::vector<wchar_t> buffer(PATH_MAX);
     ::GetModuleFileNameW(NULL, buffer.data(), buffer.size());
     std::string path;
