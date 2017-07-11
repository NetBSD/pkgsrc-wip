$NetBSD$

--- test/Verifier/gcroot-meta.ll.orig	2017-07-05 18:39:48.000000000 +0000
+++ test/Verifier/gcroot-meta.ll
@@ -1,4 +1,4 @@
-; RUN: not llvm-as < %s >& /dev/null
+; RUN: not llvm-as < %s > /dev/null 2>&1
 ; PR1633
 
 %meta = type { i8* }
