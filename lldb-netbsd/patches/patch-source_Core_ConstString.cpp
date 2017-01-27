$NetBSD$

--- source/Core/ConstString.cpp.orig	2016-12-17 10:30:30.000000000 +0000
+++ source/Core/ConstString.cpp
@@ -19,10 +19,15 @@
 #include "llvm/ADT/StringMap.h"
 #include "llvm/Support/RWMutex.h"
 
+#include "llvm/Support/Atomic.h"
+
 // Project includes
 #include "lldb/Core/Stream.h"
 
 using namespace lldb_private;
+//
+using namespace llvm;
+//using namespace sys;
 
 class Pool {
 public:
@@ -190,11 +195,11 @@ protected:
 // global destructor chain is run, and trying to make sure no destructors
 // touch ConstStrings is difficult.  So we leak the pool instead.
 //----------------------------------------------------------------------
+LLVM_DEFINE_ONCE_FLAG(g_pool_initialization_flag);
 static Pool &StringPool() {
-  static std::once_flag g_pool_initialization_flag;
   static Pool *g_string_pool = nullptr;
 
-  std::call_once(g_pool_initialization_flag,
+  llvm::call_once(g_pool_initialization_flag,
                  []() { g_string_pool = new Pool(); });
 
   return *g_string_pool;
