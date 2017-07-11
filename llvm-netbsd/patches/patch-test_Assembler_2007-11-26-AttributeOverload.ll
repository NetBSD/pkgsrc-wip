$NetBSD$

--- test/Assembler/2007-11-26-AttributeOverload.ll.orig	2017-07-05 18:39:50.000000000 +0000
+++ test/Assembler/2007-11-26-AttributeOverload.ll
@@ -1,4 +1,4 @@
-; RUN: not llvm-as < %s >& /dev/null
+; RUN: not llvm-as < %s > /dev/null 2>&1
 
 declare i32 @atoi(i8*) nounwind readonly
 declare i32 @atoi(i8*)
