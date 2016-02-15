$NetBSD$

--- src/jit/rationalize.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/jit/rationalize.cpp
@@ -566,8 +566,8 @@ void Rationalizer::RenameUpdatedVars(Loc
     rename->ZeroAll();
     unexp->ZeroAll();
     
-    int *renameMap = (int *) alloca(sizeof(int) * comp->lvaCount);
-    var_types *renameTypeMap = (var_types *) alloca(sizeof(var_types) * comp->lvaCount);
+    int *renameMap = (int *) Alloca(sizeof(int) * comp->lvaCount);
+    var_types *renameTypeMap = (var_types *) Alloca(sizeof(var_types) * comp->lvaCount);
 
     // find locals that are redefined within the tree
     foreach_treenode_execution_order(tree, statement)
