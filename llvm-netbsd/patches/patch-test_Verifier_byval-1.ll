$NetBSD$

--- test/Verifier/byval-1.ll.orig	2017-07-05 18:39:48.000000000 +0000
+++ test/Verifier/byval-1.ll
@@ -1,2 +1,2 @@
-; RUN: not llvm-as < %s >& /dev/null
+; RUN: not llvm-as < %s > /dev/null 2>&1
 declare void @h(i32 byval %num)
