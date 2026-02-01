$NetBSD$

commit #cd7e633d
Fix for Qt6.10.1: Explicitly cast unscoped enums to int 

https://gitlab.kitware.com/paraview/paraview/-/commit/cd7e633df299c29e8e76c34df83d8c67dfb386a1

--- Qt/Core/pqQVTKWidgetEventTranslator.cxx.orig	2026-01-26 16:07:36.121167406 +0000
+++ Qt/Core/pqQVTKWidgetEventTranslator.cxx
@@ -90,8 +90,8 @@ bool pqQVTKWidgetEventTranslator::transl
               .arg(normalized_x)
               .arg(normalized_y)
               .arg(mouseEvent->button())
-              .arg(mouseEvent->buttons())
-              .arg(mouseEvent->modifiers()));
+              .arg(static_cast<int>(mouseEvent->buttons())
+              .arg(static_cast<int>(mouseEvent->modifiers())));
         }
         return true;
         break;
@@ -118,15 +118,15 @@ bool pqQVTKWidgetEventTranslator::transl
               .arg(normalized_x)
               .arg(normalized_y)
               .arg(mouseEvent->button())
-              .arg(mouseEvent->buttons())
-              .arg(mouseEvent->modifiers()));
+              .arg(static_cast<int>(mouseEvent->buttons()))
+              .arg(static_cast<int>(mouseEvent->modifiers())));
           Q_EMIT recordEvent(widget, "mouseRelease",
             QString("(%1,%2,%3,%4,%5)")
               .arg(normalized_x)
               .arg(normalized_y)
               .arg(mouseEvent->button())
-              .arg(mouseEvent->buttons())
-              .arg(mouseEvent->modifiers()));
+              .arg(static_cast<int>(mouseEvent->buttons()))
+              .arg(static_cast<int>(mouseEvent->modifiers())));
         }
         return true;
         break;
