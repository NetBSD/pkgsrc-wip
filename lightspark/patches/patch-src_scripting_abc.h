$NetBSD: patch-src_scripting_abc.h,v 1.2 2014/03/29 01:03:06 nsloss Exp $

Add definitions to work with llvm 3.4. Should work with 3.5.

--- src/scripting/abc.h.orig	2013-03-16 11:19:18.000000000 +0000
+++ src/scripting/abc.h
@@ -32,6 +32,9 @@
 #include "scripting/abcutils.h"
 #include "scripting/abctypes.h"
 #include "scripting/flash/system/flashsystem.h"
+#ifdef LLVM_34
+#include <llvm/IR/LegacyPassManager.h>
+#endif
 
 namespace llvm {
 	class ExecutionEngine;
@@ -428,7 +431,11 @@ public:
 	MemoryAccount* vmDataMemory;
 
 	llvm::ExecutionEngine* ex;
+#ifdef LLVM_34
+	llvm::legacy::FunctionPassManager* FPM;
+#else
 	llvm::FunctionPassManager* FPM;
+#endif
 	llvm::LLVMContext& llvm_context();
 
 	ABCVm(SystemState* s, MemoryAccount* m) DLL_PUBLIC;
