$NetBSD$

--- lld/ELF/Config.h.orig	2019-11-01 18:04:25.969170065 +0000
+++ lld/ELF/Config.h
@@ -13,6 +13,7 @@
 #include "llvm/ADT/MapVector.h"
 #include "llvm/ADT/StringRef.h"
 #include "llvm/ADT/StringSet.h"
+#include "llvm/ADT/Triple.h"
 #include "llvm/BinaryFormat/ELF.h"
 #include "llvm/Support/CachePruning.h"
 #include "llvm/Support/CodeGen.h"
@@ -150,6 +151,7 @@ struct Configuration {
   bool enableNewDtags;
   bool executeOnly;
   bool exportDynamic;
+  bool fixCortexA53Errata835769;
   bool fixCortexA53Errata843419;
   bool fixCortexA8;
   bool forceBTI;
@@ -311,6 +313,10 @@ struct Configuration {
 
   // 4 for ELF32, 8 for ELF64.
   int wordsize;
+
+  // Target triple, inferred from program name or defaulted to LLVM
+  // default target.
+  llvm::Triple targetTriple;
 };
 
 // The only instance of Configuration struct.
