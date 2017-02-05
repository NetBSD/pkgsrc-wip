$NetBSD$

--- source/Commands/CommandObjectPlatform.cpp.orig	2017-02-02 15:43:50.000000000 +0000
+++ source/Commands/CommandObjectPlatform.cpp
@@ -29,6 +29,7 @@
 #include "lldb/Target/Process.h"
 
 #include "llvm/ADT/SmallString.h"
+#include "llvm/Support/Threading.h"
 
 using namespace lldb;
 using namespace lldb_private;
@@ -1248,8 +1249,8 @@ protected:
   public:
     CommandOptions()
         : Options(), match_info(), show_args(false), verbose(false) {
-      static std::once_flag g_once_flag;
-      std::call_once(g_once_flag, []() {
+      static llvm::once_flag g_once_flag;
+      llvm::call_once(g_once_flag, []() {
         PosixPlatformCommandOptionValidator *posix_validator =
             new PosixPlatformCommandOptionValidator();
         for (auto &Option : g_platform_process_list_options) {
