$NetBSD$

--- include/llvm/CodeGen/Passes.h.orig	2017-02-02 23:04:55.000000000 +0000
+++ include/llvm/CodeGen/Passes.h
@@ -418,7 +418,7 @@ namespace llvm {
   Registry.registerPass(*PI, true);                                            \
   return PI;                                                                   \
   }                                                                            \
-  LLVM_DEFINE_ONCE_FLAG(Initialize##passName##PassFlag);                       \
+  static llvm::once_flag Initialize##passName##PassFlag;                       \
   void llvm::initialize##passName##Pass(PassRegistry &Registry) {              \
     llvm::call_once(Initialize##passName##PassFlag,                            \
                     initialize##passName##PassOnce, std::ref(Registry));       \
