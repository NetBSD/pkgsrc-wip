$NetBSD$

--- source/Utility/ConstString.cpp.orig	2017-02-05 16:52:24.757854153 +0000
+++ source/Utility/ConstString.cpp
@@ -20,6 +20,7 @@
 #include "llvm/Support/RWMutex.h"
 
 // Project includes
+#include "llvm/Support/Threading.h"
 #include "lldb/Utility/Stream.h"
 
 using namespace lldb_private;
@@ -191,10 +192,10 @@ protected:
 // touch ConstStrings is difficult.  So we leak the pool instead.
 //----------------------------------------------------------------------
 static Pool &StringPool() {
-  static std::once_flag g_pool_initialization_flag;
+  static llvm::once_flag g_pool_initialization_flag;
   static Pool *g_string_pool = nullptr;
 
-  std::call_once(g_pool_initialization_flag,
+  llvm::call_once(g_pool_initialization_flag,
                  []() { g_string_pool = new Pool(); });
 
   return *g_string_pool;
