$NetBSD$

--- src/jit/gentree.cpp.orig	2016-02-03 00:16:44.000000000 +0000
+++ src/jit/gentree.cpp
@@ -4776,7 +4776,7 @@ GenTree::VtablePtr GenTree::GetVtableFor
                 assert(!IsExOp(opKind));
                 assert(OperIsSimple(oper) || OperIsLeaf(oper));
                 // Need to provide non-null operands.
-                Compiler* comp = (Compiler*)_alloca(sizeof(Compiler));
+                Compiler* comp = (Compiler*)Alloca(sizeof(Compiler));
                 GenTreeIntCon dummyOp(TYP_INT, 0);
                 GenTreeOp gt(oper, TYP_INT, &dummyOp, ((opKind & GTK_UNOP) ? NULL : &dummyOp));
                 s_vtableForOp = *reinterpret_cast<VtablePtr*>(&gt);
