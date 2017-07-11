$NetBSD$

--- test/Verifier/2009-05-29-InvokeResult1.ll.orig	2017-07-05 18:39:47.000000000 +0000
+++ test/Verifier/2009-05-29-InvokeResult1.ll
@@ -1,4 +1,4 @@
-; RUN: not llvm-as < %s >& /dev/null
+; RUN: not llvm-as < %s > /dev/null 2>&1
 
 declare i32 @v()
 
