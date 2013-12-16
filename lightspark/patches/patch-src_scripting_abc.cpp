$NetBSD: patch-src_scripting_abc.cpp,v 1.1 2013/12/16 07:54:18 nsloss Exp $

Add definitions to compile with llvm 3.3

--- src/scripting/abc.cpp.orig	2013-03-16 11:19:18.000000000 +0000
+++ src/scripting/abc.cpp
@@ -23,12 +23,22 @@
 
 #include "compat.h"
 
+#ifdef LLVM_33
+#include <llvm/IR/Module.h>
+#else
 #include <llvm/Module.h>
+#endif
 #include <llvm/ExecutionEngine/ExecutionEngine.h>
 #include <llvm/ExecutionEngine/JIT.h>
 #include <llvm/PassManager.h>
+#ifdef LLVM_33
+#include <llvm/IR/LLVMContext.h>
+#else
 #include <llvm/LLVMContext.h>
-#ifdef HAVE_DATALAYOUT_H
+#endif
+#ifdef LLVM_33
+#  include <llvm/IR/DataLayout.h>
+#elif defined(HAVE_DATALAYOUT_H)
 #  include <llvm/DataLayout.h>
 #else
 #  include <llvm/Target/TargetData.h>
@@ -1464,14 +1474,14 @@ void ABCVm::Run(ABCVm* th)
 
 	if(th->m_sys->useJit)
 	{
-#ifdef LLVM_31
+#if defined(LLVM_31) || defined(LLVM_33)
 		llvm::TargetOptions Opts;
 		Opts.JITExceptionHandling = true;
 #else
 		llvm::JITExceptionHandling = true;
 #endif
 #ifndef NDEBUG
-#ifdef LLVM_31
+#if defined(LLVM_31) || defined(LLVM_33)
 		Opts.JITEmitDebugInfo = true;
 #else
 		llvm::JITEmitDebugInfo = true;
@@ -1481,7 +1491,7 @@ void ABCVm::Run(ABCVm* th)
 		th->module=new llvm::Module(llvm::StringRef("abc jit"),th->llvm_context());
 		llvm::EngineBuilder eb(th->module);
 		eb.setEngineKind(llvm::EngineKind::JIT);
-#ifdef LLVM_31
+#if defined(LLVM_31) || defined(LLVM_33)
 		eb.setTargetOptions(Opts);
 #endif
 		eb.setOptLevel(llvm::CodeGenOpt::Default);
@@ -1489,7 +1499,7 @@ void ABCVm::Run(ABCVm* th)
 		assert_and_throw(th->ex);
 
 		th->FPM=new llvm::FunctionPassManager(th->module);
-#ifdef HAVE_DATALAYOUT_H
+#if defined(HAVE_DATALAYOUT_H) || defined(LLVM_33)
 		th->FPM->add(new llvm::DataLayout(*th->ex->getDataLayout()));
 #else
 		th->FPM->add(new llvm::TargetData(*th->ex->getTargetData()));
