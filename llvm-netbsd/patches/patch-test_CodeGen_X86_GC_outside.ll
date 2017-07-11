$NetBSD$

--- test/CodeGen/X86/GC/outside.ll.orig	2017-07-05 18:39:17.000000000 +0000
+++ test/CodeGen/X86/GC/outside.ll
@@ -1,4 +1,4 @@
-; RUN: not llvm-as < %s >& /dev/null
+; RUN: not llvm-as < %s > /dev/null 2>&1
 
 declare void @llvm.gcroot(i8**, i8*)
 
