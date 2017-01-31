$NetBSD$

--- source/Commands/CommandObjectPlatform.cpp.orig	2016-12-17 10:29:27.000000000 +0000
+++ source/Commands/CommandObjectPlatform.cpp
@@ -30,6 +30,7 @@
 #include "lldb/Utility/Utils.h"
 
 #include "llvm/ADT/SmallString.h"
+#include "llvm/Support/Threading.h"
 
 using namespace lldb;
 using namespace lldb_private;
@@ -1249,8 +1250,8 @@ protected:
   public:
     CommandOptions()
         : Options(), match_info(), show_args(false), verbose(false) {
-      static std::once_flag g_once_flag;
-      std::call_once(g_once_flag, []() {
+      LLVM_DEFINE_ONCE_FLAG(g_once_flag);
+      llvm::call_once(g_once_flag, []() {
         PosixPlatformCommandOptionValidator *posix_validator =
             new PosixPlatformCommandOptionValidator();
         for (auto &Option : g_platform_process_list_options) {
