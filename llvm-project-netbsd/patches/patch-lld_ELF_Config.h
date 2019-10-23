$NetBSD$

--- lld/ELF/Config.h.orig	2019-10-23 20:24:31.975278079 +0000
+++ lld/ELF/Config.h
@@ -13,6 +13,7 @@
 #include "llvm/ADT/MapVector.h"
 #include "llvm/ADT/StringRef.h"
 #include "llvm/ADT/StringSet.h"
+#include "llvm/ADT/Triple.h"
 #include "llvm/BinaryFormat/ELF.h"
 #include "llvm/Support/CachePruning.h"
 #include "llvm/Support/CodeGen.h"
@@ -64,6 +65,9 @@ enum class ARMVFPArgKind { Default, Base
 // For -z noseparate-code, -z separate-code and -z separate-loadable-segments.
 enum class SeparateSegmentKind { None, Code, Loadable };
 
+// For -z *stack
+enum class GnuStackKind { None, Exec, NoExec };
+
 struct SymbolVersion {
   llvm::StringRef name;
   bool isExternCpp;
@@ -147,6 +151,7 @@ struct Configuration {
   bool enableNewDtags;
   bool executeOnly;
   bool exportDynamic;
+  bool fixCortexA53Errata835769;
   bool fixCortexA53Errata843419;
   bool fixCortexA8;
   bool forceBTI;
@@ -208,6 +213,7 @@ struct Configuration {
   bool zNodefaultlib;
   bool zNodelete;
   bool zNodlopen;
+  bool zNognustack;
   bool zNow;
   bool zOrigin;
   bool zRelro;
@@ -216,6 +222,7 @@ struct Configuration {
   bool zRetpolineplt;
   bool zWxneeded;
   DiscardPolicy discard;
+  GnuStackKind zGnustack;
   ICFLevel icf;
   OrphanHandlingPolicy orphanHandling;
   SortSectionPolicy sortSection;
@@ -306,6 +313,10 @@ struct Configuration {
 
   // 4 for ELF32, 8 for ELF64.
   int wordsize;
+
+  // Target triple, inferred from program name or defaulted to LLVM
+  // default target.
+  llvm::Triple targetTriple;
 };
 
 // The only instance of Configuration struct.
