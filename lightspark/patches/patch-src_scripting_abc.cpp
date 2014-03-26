$NetBSD: patch-src_scripting_abc.cpp,v 1.2 2014/03/26 06:02:43 nsloss Exp $

Add definitions to compile with llvm 3.3
Add definitions to compile with llvm 3.4 Should work with 3.5

--- src/scripting/abc.cpp.orig	2013-03-16 11:19:18.000000000 +0000
+++ src/scripting/abc.cpp
@@ -23,12 +23,26 @@
 
 #include "compat.h"
 
+#ifdef LLVM_33
+#include <llvm/IR/Module.h>
+#else
 #include <llvm/Module.h>
+#endif
 #include <llvm/ExecutionEngine/ExecutionEngine.h>
 #include <llvm/ExecutionEngine/JIT.h>
+#ifdef LLVM_34
+#include <llvm/IR/LegacyPassManager.h>
+#else
 #include <llvm/PassManager.h>
+#endif
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
@@ -1464,14 +1478,16 @@ void ABCVm::Run(ABCVm* th)
 
 	if(th->m_sys->useJit)
 	{
-#ifdef LLVM_31
+#if defined(LLVM_31) || defined(LLVM_33)
 		llvm::TargetOptions Opts;
+#if !defined(LLVM_34)
 		Opts.JITExceptionHandling = true;
+#endif
 #else
 		llvm::JITExceptionHandling = true;
 #endif
 #ifndef NDEBUG
-#ifdef LLVM_31
+#if defined(LLVM_31) || defined(LLVM_33)
 		Opts.JITEmitDebugInfo = true;
 #else
 		llvm::JITEmitDebugInfo = true;
@@ -1481,15 +1497,19 @@ void ABCVm::Run(ABCVm* th)
 		th->module=new llvm::Module(llvm::StringRef("abc jit"),th->llvm_context());
 		llvm::EngineBuilder eb(th->module);
 		eb.setEngineKind(llvm::EngineKind::JIT);
-#ifdef LLVM_31
+#if defined(LLVM_31) || defined(LLVM_33)
 		eb.setTargetOptions(Opts);
 #endif
 		eb.setOptLevel(llvm::CodeGenOpt::Default);
 		th->ex=eb.create();
 		assert_and_throw(th->ex);
 
+#ifdef LLVM_34
+		th->FPM=new llvm::legacy::FunctionPassManager(th->module);
+#else
 		th->FPM=new llvm::FunctionPassManager(th->module);
-#ifdef HAVE_DATALAYOUT_H
+#endif
+#if defined(HAVE_DATALAYOUT_H) || defined(LLVM_33)
 		th->FPM->add(new llvm::DataLayout(*th->ex->getDataLayout()));
 #else
 		th->FPM->add(new llvm::TargetData(*th->ex->getTargetData()));
