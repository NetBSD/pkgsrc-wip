$NetBSD$

* fix gcc warnings
  from upstream:
  https://codereview.qt-project.org/c/qt/qtdatavis3d/+/356216

--- src/datavisualization/data/barrenderitem_p.h.orig	2021-07-01 13:49:26.302346756 +0000
+++ src/datavisualization/data/barrenderitem_p.h
@@ -49,6 +49,7 @@ class BarRenderItem : public AbstractRen
 public:
     BarRenderItem();
     BarRenderItem(const BarRenderItem &other);
+    BarRenderItem &operator=(const BarRenderItem &other) = default;    
     virtual ~BarRenderItem();
 
     // Position relative to data window (for bar label generation)
@@ -76,6 +77,7 @@ class BarRenderSliceItem : public BarRen
 public:
     BarRenderSliceItem();
     BarRenderSliceItem(const BarRenderSliceItem &other);
+    BarRenderSliceItem &operator=(const BarRenderSliceItem &other) = default;
     virtual ~BarRenderSliceItem();
 
     void setItem(const BarRenderItem &renderItem);
