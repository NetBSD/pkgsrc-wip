$NetBSD$

--- source/Plugins/Platform/MacOSX/PlatformDarwin.cpp.orig	2016-12-14 14:10:24.000000000 +0000
+++ source/Plugins/Platform/MacOSX/PlatformDarwin.cpp
@@ -40,6 +40,7 @@
 #include "lldb/Target/Process.h"
 #include "lldb/Target/Target.h"
 #include "llvm/ADT/STLExtras.h"
+#include "llvm/Support/Threading.h"
 
 #if defined(__APPLE__)
 #include <TargetConditionals.h> // for TARGET_OS_TV, TARGET_OS_WATCH
@@ -1452,8 +1453,8 @@ static FileSpec CheckPathForXcode(const 
 
 static FileSpec GetXcodeContentsPath() {
   static FileSpec g_xcode_filespec;
-  static std::once_flag g_once_flag;
-  std::call_once(g_once_flag, []() {
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
+  llvm::call_once(g_once_flag, []() {
 
     FileSpec fspec;
 
@@ -1835,8 +1836,8 @@ lldb_private::FileSpec PlatformDarwin::L
 
   // Find the global list of directories that we will search for
   // executables once so we don't keep doing the work over and over.
-  static std::once_flag g_once_flag;
-  std::call_once(g_once_flag, []() {
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
+  llvm::call_once(g_once_flag, []() {
 
     // When locating executables, trust the DEVELOPER_DIR first if it is set
     FileSpec xcode_contents_dir = GetXcodeContentsPath();
