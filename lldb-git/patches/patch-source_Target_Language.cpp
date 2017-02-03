$NetBSD$

--- source/Target/Language.cpp.orig	2017-02-02 23:56:41.000000000 +0000
+++ source/Target/Language.cpp
@@ -20,6 +20,8 @@
 #include "lldb/Target/Target.h"
 #include "lldb/Utility/Stream.h"
 
+#include "llvm/Support/Threading.h"
+
 using namespace lldb;
 using namespace lldb_private;
 using namespace lldb_private::formatters;
@@ -29,9 +31,9 @@ typedef std::map<lldb::LanguageType, Lan
 
 static LanguagesMap &GetLanguagesMap() {
   static LanguagesMap *g_map = nullptr;
-  static std::once_flag g_initialize;
+  LLVM_DEFINE_ONCE_FLAG(g_initialize);
 
-  std::call_once(g_initialize, [] {
+  llvm::call_once(g_initialize, [] {
     g_map = new LanguagesMap(); // NOTE: INTENTIONAL LEAK due to global
                                 // destructor chain
   });
@@ -40,9 +42,9 @@ static LanguagesMap &GetLanguagesMap() {
 }
 static std::mutex &GetLanguagesMutex() {
   static std::mutex *g_mutex = nullptr;
-  static std::once_flag g_initialize;
+  LLVM_DEFINE_ONCE_FLAG(g_initialize);
 
-  std::call_once(g_initialize, [] {
+  llvm::call_once(g_initialize, [] {
     g_mutex = new std::mutex(); // NOTE: INTENTIONAL LEAK due to global
                                 // destructor chain
   });
