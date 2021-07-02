$NetBSD$

* fix gcc warnings
  from upstream:
  https://codereview.qt-project.org/c/qt/qtdatavis3d/+/356216

--- src/datavisualization/data/scatterrenderitem_p.h.orig	2021-07-01 13:53:43.222351785 +0000
+++ src/datavisualization/data/scatterrenderitem_p.h
@@ -49,6 +49,7 @@ class ScatterRenderItem : public Abstrac
 public:
     ScatterRenderItem();
     ScatterRenderItem(const ScatterRenderItem &other);
+    ScatterRenderItem &operator=(const ScatterRenderItem &other) = default;
     virtual ~ScatterRenderItem();
 
     inline const QVector3D &position() const { return m_position; }
