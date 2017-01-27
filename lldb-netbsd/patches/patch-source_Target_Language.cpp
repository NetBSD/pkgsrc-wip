$NetBSD$

--- source/Target/Language.cpp.orig	2016-12-17 10:30:23.000000000 +0000
+++ source/Target/Language.cpp
@@ -20,18 +20,21 @@
 #include "lldb/Symbol/TypeList.h"
 #include "lldb/Target/Target.h"
 
+#include "llvm/Support/Threading.h"
+
 using namespace lldb;
 using namespace lldb_private;
 using namespace lldb_private::formatters;
+using namespace llvm;
 
 typedef std::unique_ptr<Language> LanguageUP;
 typedef std::map<lldb::LanguageType, LanguageUP> LanguagesMap;
 
 static LanguagesMap &GetLanguagesMap() {
   static LanguagesMap *g_map = nullptr;
-  static std::once_flag g_initialize;
+  LLVM_DEFINE_ONCE_FLAG(g_initialize);
 
-  std::call_once(g_initialize, [] {
+  llvm::call_once(g_initialize, [] {
     g_map = new LanguagesMap(); // NOTE: INTENTIONAL LEAK due to global
                                 // destructor chain
   });
@@ -40,9 +43,9 @@ static LanguagesMap &GetLanguagesMap() {
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
