$NetBSD: patch-src_scripting_abc.h,v 1.1 2014/03/26 06:02:43 nsloss Exp $

Add definitions to work with llvm 3.4. Should work with 3.5.

--- src/scripting/abc.h.orig	2013-03-16 11:19:18.000000000 +0000
+++ src/scripting/abc.h
@@ -32,10 +32,17 @@
 #include "scripting/abcutils.h"
 #include "scripting/abctypes.h"
 #include "scripting/flash/system/flashsystem.h"
+#ifdef LLVM_34
+#include <llvm/IR/LegacyPassManager.h>
+#endif
 
 namespace llvm {
 	class ExecutionEngine;
+#ifdef LLVM_34
+	class FunctionPassManager;
+#else
 	class FunctionPassManager;
+#endif
 	class FunctionType;
 	class Function;
 	class Module;
@@ -428,7 +435,11 @@ public:
 	MemoryAccount* vmDataMemory;
 
 	llvm::ExecutionEngine* ex;
+#ifdef LLVM_34
+	llvm::legacy::FunctionPassManager* FPM;
+#else
 	llvm::FunctionPassManager* FPM;
+#endif
 	llvm::LLVMContext& llvm_context();
 
 	ABCVm(SystemState* s, MemoryAccount* m) DLL_PUBLIC;
