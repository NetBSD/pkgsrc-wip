$NetBSD$

--- src/jit/ssabuilder.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/jit/ssabuilder.cpp
@@ -224,7 +224,7 @@ SsaBuilder::SsaBuilder(Compiler* pCompil
 int SsaBuilder::TopologicalSort(BasicBlock** postOrder, int count)
 {
     // Allocate and initialize visited flags.
-    bool* visited = (bool*) alloca(count * sizeof(bool));
+    bool* visited = (bool*) Alloca(count * sizeof(bool));
     memset(visited, 0, count * sizeof(bool));
 
     // Display basic blocks.
@@ -1626,7 +1626,7 @@ void SsaBuilder::Build()
     JITDUMP("[SsaBuilder] Max block count is %d.\n", blockCount);
 
     // Allocate the postOrder array for the graph.
-    BasicBlock** postOrder = (BasicBlock**) alloca(blockCount * sizeof(BasicBlock*));
+    BasicBlock** postOrder = (BasicBlock**) Alloca(blockCount * sizeof(BasicBlock*));
 
     // Topologically sort the graph.
     int count = TopologicalSort(postOrder, blockCount);
