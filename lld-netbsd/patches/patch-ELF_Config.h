$NetBSD: patch-ELF_Config.h,v 1.1 2019/02/01 16:30:00 mgorny Exp $

Add support for customizing LLD behavior on target triple.
https://reviews.llvm.org/D56650

Add '-z nognustack' option to disable emitting PT_GNU_STACK.
https://reviews.llvm.org/D56554

--- ELF/Config.h.orig	2019-02-01 23:06:35.000000000 +0000
+++ ELF/Config.h
@@ -13,6 +13,7 @@
 #include "llvm/ADT/MapVector.h"
 #include "llvm/ADT/StringRef.h"
 #include "llvm/ADT/StringSet.h"
+#include "llvm/ADT/Triple.h"
 #include "llvm/BinaryFormat/ELF.h"
 #include "llvm/Support/CachePruning.h"
 #include "llvm/Support/CodeGen.h"
@@ -194,6 +195,7 @@ struct Configuration {
   bool ZNodefaultlib;
   bool ZNodelete;
   bool ZNodlopen;
+  bool ZNognustack;
   bool ZNow;
   bool ZOrigin;
   bool ZRelro;
@@ -277,6 +279,10 @@ struct Configuration {
 
   // 4 for ELF32, 8 for ELF64.
   int Wordsize;
+
+  // Target triple, inferred from program name or defaulted to LLVM
+  // default target.
+  llvm::Triple TargetTriple;
 };
 
 // The only instance of Configuration struct.
