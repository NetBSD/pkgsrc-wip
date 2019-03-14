$NetBSD$

--- ELF/Config.h.orig	2019-03-14 17:35:11.000000000 +0000
+++ ELF/Config.h
@@ -13,6 +13,7 @@
 #include "llvm/ADT/MapVector.h"
 #include "llvm/ADT/StringRef.h"
 #include "llvm/ADT/StringSet.h"
+#include "llvm/ADT/Triple.h"
 #include "llvm/BinaryFormat/ELF.h"
 #include "llvm/Support/CachePruning.h"
 #include "llvm/Support/CodeGen.h"
@@ -198,6 +199,7 @@ struct Configuration {
   bool ZNodefaultlib;
   bool ZNodelete;
   bool ZNodlopen;
+  bool ZNognustack;
   bool ZNow;
   bool ZOrigin;
   bool ZRelro;
@@ -295,6 +297,10 @@ struct Configuration {
 
   // 4 for ELF32, 8 for ELF64.
   int Wordsize;
+
+  // Target triple, inferred from program name or defaulted to LLVM
+  // default target.
+  llvm::Triple TargetTriple;
 };
 
 // The only instance of Configuration struct.
