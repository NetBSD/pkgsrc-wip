$NetBSD: patch-v8_src_x64_lithium-codegen-x64.cc,v 1.1.1.1 2011/05/03 19:53:18 genolopolis Exp $

--- deps/v8/src/x64/lithium-codegen-x64.cc.orig	2011-04-13 08:24:39.000000000 +0000
+++ deps/v8/src/x64/lithium-codegen-x64.cc
@@ -786,7 +786,7 @@ void LCodeGen::DoBranch(LBranch* instr) 
       __ j(equal, true_label);
       __ CompareRoot(reg, Heap::kFalseValueRootIndex);
       __ j(equal, false_label);
-      __ SmiCompare(reg, Smi::FromInt(0));
+      __ Cmp(reg, Smi::FromInt(0));
       __ j(equal, false_label);
       __ JumpIfSmi(reg, true_label);
 
