$NetBSD$

commit #cd7e633d
Fix for Qt6.10.1: Explicitly cast unscoped enums to int 

https://gitlab.kitware.com/paraview/paraview/-/commit/cd7e633df299c29e8e76c34df83d8c67dfb386a1

--- Qt/Core/pqFlatTreeViewEventTranslator.cxx.orig	2026-01-26 16:06:53.762654764 +0000
+++ Qt/Core/pqFlatTreeViewEventTranslator.cxx
@@ -73,8 +73,8 @@ bool pqFlatTreeViewEventTranslator::tran
 
       QString info = QString("%1,%2,%3,%4,%5,%6")
                        .arg(mouseEvent->button())
-                       .arg(mouseEvent->buttons())
-                       .arg(mouseEvent->modifiers())
+                       .arg(static_cast<int>(mouseEvent->buttons()))
+                       .arg(static_cast<int>(mouseEvent->modifiers()))
                        .arg(relPt.x())
                        .arg(relPt.y())
                        .arg(idxStr);
