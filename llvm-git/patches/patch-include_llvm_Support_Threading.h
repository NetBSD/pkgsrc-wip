$NetBSD$

--- include/llvm/Support/Threading.h.orig	2016-12-14 12:33:46.000000000 +0000
+++ include/llvm/Support/Threading.h
@@ -71,7 +71,7 @@ namespace llvm {
 
   /// This macro is the only way you should define your once flag for LLVM's
   /// call_once.
-#define LLVM_DEFINE_ONCE_FLAG(flag) static once_flag flag = Uninitialized
+#define LLVM_DEFINE_ONCE_FLAG(flag) static llvm::once_flag flag = Uninitialized
 
 #endif
 
