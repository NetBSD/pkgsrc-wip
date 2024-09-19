$NetBSD: patch-src_widgets_graphicsview_qgraphicsitem__p.h,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

--- src/qt/qtbase/src/widgets/graphicsview/qgraphicsitem_p.h.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtbase/src/widgets/graphicsview/qgraphicsitem_p.h
@@ -761,7 +761,7 @@ inline bool qt_closestItemFirst(const QG
     // item1Ancestor is now at the same level as item2Ancestor, but not the same.
     const QGraphicsItem *p1 = t1;
     const QGraphicsItem *p2 = t2;
-    while (t1 && t1 != t2) {
+    while (t1 && t2 && t1 != t2) {
         p1 = t1;
         p2 = t2;
         t1 = t1->d_ptr->parent;
