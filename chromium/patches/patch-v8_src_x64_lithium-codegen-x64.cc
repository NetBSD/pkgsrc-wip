$NetBSD: patch-v8_src_x64_lithium-codegen-x64.cc,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- v8/src/x64/lithium-codegen-x64.cc.orig	2011-04-13 08:24:39.000000000 +0000
+++ v8/src/x64/lithium-codegen-x64.cc
@@ -786,7 +786,7 @@ void LCodeGen::DoBranch(LBranch* instr) 
       __ j(equal, true_label);
       __ CompareRoot(reg, Heap::kFalseValueRootIndex);
       __ j(equal, false_label);
-      __ SmiCompare(reg, Smi::FromInt(0));
+      __ Cmp(reg, Smi::FromInt(0));
       __ j(equal, false_label);
       __ JumpIfSmi(reg, true_label);
 
