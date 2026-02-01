$NetBSD$

commit #9ba0a210
Fix for Qt6.10.1: Explicitly cast unscoped enums to int

https://gitlab.kitware.com/paraview/qttesting/-/commit/9ba0a2104840ac5ddf0b73a36d72b282bf6b03d9.patch

--- ThirdParty/QtTesting/vtkqttesting/pqAbstractItemViewEventTranslator.cxx.orig	2026-01-26 14:22:05.462417636 +0000
+++ ThirdParty/QtTesting/vtkqttesting/pqAbstractItemViewEventTranslator.cxx
@@ -90,8 +90,8 @@ bool pqAbstractItemViewEventTranslator::
 
       QString info = QString("%1,%2,%3,%4,%5,%6")
                        .arg(mouseEvent->button())
-                       .arg(mouseEvent->buttons())
-                       .arg(mouseEvent->modifiers())
+                       .arg(static_cast<int>(mouseEvent->buttons()))
+                       .arg(static_cast<int>(mouseEvent->modifiers()))
                        .arg(relPt.x())
                        .arg(relPt.y())
                        .arg(idxStr);
