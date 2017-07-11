$NetBSD$

--- test/Other/2002-01-31-CallGraph.ll.orig	2017-07-05 18:41:18.000000000 +0000
+++ test/Other/2002-01-31-CallGraph.ll
@@ -1,6 +1,6 @@
 ;  Call graph construction crash: Not handling indirect calls right
 ;
-; RUN: opt < %s -analyze -print-callgraph >& /dev/null
+; RUN: opt < %s -analyze -print-callgraph > /dev/null 2>&1
 ;
 
         %FunTy = type i32 (i32)
