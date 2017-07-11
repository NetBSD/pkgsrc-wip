$NetBSD$

--- test/Analysis/BasicAA/unreachable-block.ll.orig	2017-07-05 18:41:21.000000000 +0000
+++ test/Analysis/BasicAA/unreachable-block.ll
@@ -1,4 +1,4 @@
-; RUN: opt -basicaa -aa-eval -disable-output < %s >& /dev/null
+; RUN: opt -basicaa -aa-eval -disable-output < %s > /dev/null 2>&1
 
 ; BasicAA shouldn't infinitely recurse on the use-def cycles in
 ; unreachable code.
