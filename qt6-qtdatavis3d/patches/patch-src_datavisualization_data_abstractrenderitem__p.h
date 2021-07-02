$NetBSD$

* fix gcc warnings
  from upstream:
  https://codereview.qt-project.org/c/qt/qtdatavis3d/+/356216

--- src/datavisualization/data/abstractrenderitem_p.h.orig	2021-07-01 13:52:29.286355790 +0000
+++ src/datavisualization/data/abstractrenderitem_p.h
@@ -53,6 +53,7 @@ class AbstractRenderItem
 public:
     AbstractRenderItem();
     AbstractRenderItem(const AbstractRenderItem &other);
+    AbstractRenderItem &operator=(const AbstractRenderItem &other) = default;    
     virtual ~AbstractRenderItem();
 
     // Position in 3D scene
