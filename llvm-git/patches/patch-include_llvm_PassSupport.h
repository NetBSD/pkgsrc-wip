$NetBSD$

--- include/llvm/PassSupport.h.orig	2016-10-19 20:19:34.000000000 +0000
+++ include/llvm/PassSupport.h
@@ -41,7 +41,7 @@ class TargetMachine;
     Registry.registerPass(*PI, true);                                          \
     return PI;                                                                 \
   }                                                                            \
-  LLVM_DEFINE_ONCE_FLAG(Initialize##passName##PassFlag);                       \
+  static llvm::once_flag Initialize##passName##PassFlag;                       \
   void llvm::initialize##passName##Pass(PassRegistry &Registry) {              \
     llvm::call_once(Initialize##passName##PassFlag,                            \
                     initialize##passName##PassOnce, std::ref(Registry));       \
@@ -61,7 +61,7 @@ class TargetMachine;
   Registry.registerPass(*PI, true);                                            \
   return PI;                                                                   \
   }                                                                            \
-  LLVM_DEFINE_ONCE_FLAG(Initialize##passName##PassFlag);                       \
+  static llvm::once_flag Initialize##passName##PassFlag;                       \
   void llvm::initialize##passName##Pass(PassRegistry &Registry) {              \
     llvm::call_once(Initialize##passName##PassFlag,                            \
                     initialize##passName##PassOnce, std::ref(Registry));       \
@@ -152,7 +152,7 @@ struct RegisterAnalysisGroup : public Re
     Registry.registerAnalysisGroup(&agName::ID, 0, *AI, false, true);          \
     return AI;                                                                 \
   }                                                                            \
-  LLVM_DEFINE_ONCE_FLAG(Initialize##agName##AnalysisGroupFlag);                \
+  static llvm::once_flag Initialize##agName##AnalysisGroupFlag;                \
   void llvm::initialize##agName##AnalysisGroup(PassRegistry &Registry) {       \
     llvm::call_once(Initialize##agName##AnalysisGroupFlag,                     \
                     initialize##agName##AnalysisGroupOnce,                     \
@@ -173,7 +173,7 @@ struct RegisterAnalysisGroup : public Re
                                    true);                                      \
     return AI;                                                                 \
   }                                                                            \
-  LLVM_DEFINE_ONCE_FLAG(Initialize##passName##PassFlag);                       \
+  static llvm::once_flag Initialize##passName##PassFlag;                       \
   void llvm::initialize##passName##Pass(PassRegistry &Registry) {              \
     llvm::call_once(Initialize##passName##PassFlag,                            \
                     initialize##passName##PassOnce, std::ref(Registry));       \
@@ -194,7 +194,7 @@ struct RegisterAnalysisGroup : public Re
   Registry.registerAnalysisGroup(&agName::ID, &passName::ID, *AI, def, true);  \
   return AI;                                                                   \
   }                                                                            \
-  LLVM_DEFINE_ONCE_FLAG(Initialize##passName##PassFlag);                       \
+  static llvm::once_flag Initialize##passName##PassFlag;                       \
   void llvm::initialize##passName##Pass(PassRegistry &Registry) {              \
     llvm::call_once(Initialize##passName##PassFlag,                            \
                     initialize##passName##PassOnce, std::ref(Registry));       \
