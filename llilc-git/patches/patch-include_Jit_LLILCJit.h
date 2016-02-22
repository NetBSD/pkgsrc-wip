$NetBSD$

--- include/Jit/LLILCJit.h.orig	2016-02-22 20:43:07.000000000 +0000
+++ include/Jit/LLILCJit.h
@@ -25,7 +25,8 @@
 #include "llvm/Support/ThreadLocal.h"
 #include "llvm/ExecutionEngine/Orc/IRCompileLayer.h"
 #include "llvm/ExecutionEngine/Orc/NullResolver.h"
-#include "llvm/Config/config.h"
+//#include "llvm/Config/config.h"
+#include "llvm/Config/llvm-config.h"
 
 class ABIInfo;
 class GcInfo;
