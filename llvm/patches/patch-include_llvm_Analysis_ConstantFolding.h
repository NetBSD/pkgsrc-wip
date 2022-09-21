$NetBSD$

Fix SunOS CS conflict not handled by include/llvm-c/DataTypes.h

--- include/llvm/Analysis/ConstantFolding.h.orig	2022-09-20 06:05:50.000000000 +0000
+++ include/llvm/Analysis/ConstantFolding.h
@@ -19,6 +19,10 @@
 #ifndef LLVM_ANALYSIS_CONSTANTFOLDING_H
 #define LLVM_ANALYSIS_CONSTANTFOLDING_H
 
+#ifdef __sun
+#undef CS
+#endif
+
 #include <stdint.h>
 
 namespace llvm {
