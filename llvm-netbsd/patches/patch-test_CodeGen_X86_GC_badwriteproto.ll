$NetBSD$

--- test/CodeGen/X86/GC/badwriteproto.ll.orig	2017-07-05 18:39:17.000000000 +0000
+++ test/CodeGen/X86/GC/badwriteproto.ll
@@ -1,4 +1,4 @@
-; RUN: not llvm-as < %s >& /dev/null
+; RUN: not llvm-as < %s > /dev/null 2>&1
 
 	%list = type { i32, %list* }
 
