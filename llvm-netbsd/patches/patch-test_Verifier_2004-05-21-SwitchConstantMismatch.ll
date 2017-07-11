$NetBSD$

--- test/Verifier/2004-05-21-SwitchConstantMismatch.ll.orig	2017-07-05 18:39:48.000000000 +0000
+++ test/Verifier/2004-05-21-SwitchConstantMismatch.ll
@@ -1,4 +1,4 @@
-; RUN: not llvm-as < %s >& /dev/null
+; RUN: not llvm-as < %s > /dev/null 2>&1
 
 
 
