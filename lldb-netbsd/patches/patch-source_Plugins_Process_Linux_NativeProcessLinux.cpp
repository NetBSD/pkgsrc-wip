$NetBSD$

--- source/Plugins/Process/Linux/NativeProcessLinux.cpp.orig	2016-12-17 10:30:08.000000000 +0000
+++ source/Plugins/Process/Linux/NativeProcessLinux.cpp
@@ -75,9 +75,9 @@ using namespace llvm;
 
 static bool ProcessVmReadvSupported() {
   static bool is_supported;
-  static std::once_flag flag;
+  LLVM_DEFINE_ONCE_FLAG(flag);
 
-  std::call_once(flag, [] {
+  llvm::call_once(flag, [] {
     Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
 
     uint32_t source = 0x47424742;
