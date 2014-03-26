$NetBSD: patch-src_scripting_abc__codesynt.cpp,v 1.2 2014/03/26 06:02:43 nsloss Exp $

Add definitions to compile with llvm 3.3
Add definitions to compile with llvm 3.4.  Should work with 3.5.

--- src/scripting/abc_codesynt.cpp.orig	2013-03-16 11:19:18.000000000 +0000
+++ src/scripting/abc_codesynt.cpp
@@ -25,18 +25,39 @@
 #endif
 
 #include "compat.h"
+#ifdef LLVM_33
+#include <llvm/IR/Module.h>
+#include <llvm/IR/DerivedTypes.h>
+#else
 #include <llvm/Module.h>
 #include <llvm/DerivedTypes.h>
+#endif
 #include <llvm/ExecutionEngine/ExecutionEngine.h>
+#ifdef LLVM_34
+#include <llvm/IR/LegacyPassManager.h>
+#else
 #include <llvm/PassManager.h>
+#endif
+#ifdef LLVM_33
+#include <llvm/IR/Constants.h>
+#else
 #include <llvm/Constants.h>
-#ifdef HAVE_IRBUILDER_H
+#endif
+#ifdef LLVM_33
+#  include <llvm/IR/IRBuilder.h>
+#elif defined(HAVE_IRBUILDER_H)
 #  include <llvm/IRBuilder.h>
 #else
 #  include <llvm/Support/IRBuilder.h>
 #endif
+#ifdef LLVM_33
+#include <llvm/IR/LLVMContext.h>
+#else
 #include <llvm/LLVMContext.h>
-#ifdef HAVE_DATALAYOUT_H
+#endif
+#if defined(LLVM_33)
+#  include <llvm/IR/DataLayout.h>
+#elif defined(HAVE_DATALAYOUT_H)
 #  include <llvm/DataLayout.h>
 #else
 #  include <llvm/Target/TargetData.h>
@@ -279,7 +300,7 @@ void ABCVm::registerFunctions()
 	llvm::FunctionType* FT=NULL;
 
 	//Create types
-#ifdef HAVE_DATALAYOUT_H
+#if defined(HAVE_DATALAYOUT_H) || defined (LLVM_33)
 	ptr_type=ex->getDataLayout()->getIntPtrType(llvm_context());
 #else
 	ptr_type=ex->getTargetData()->getIntPtrType(llvm_context());
