$NetBSD$

* Fix build breakage

--- src/TextArea.cpp.orig	2020-02-05 05:36:17.000000000 +0000
+++ src/TextArea.cpp
@@ -27,6 +27,7 @@
 #include <QMimeData>
 #include <QPaintEvent>
 #include <QPainter>
+#include <QPainterPath>
 #include <QPoint>
 #include <QResizeEvent>
 #include <QScrollBar>
