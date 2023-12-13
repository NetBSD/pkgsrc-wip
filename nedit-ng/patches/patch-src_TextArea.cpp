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
@@ -36,7 +37,8 @@
 #include <QtDebug>
 #include <QtGlobal>
 
-#include <gsl/gsl_util>
+#include <gsl/narrow>
+#include <gsl/util>
 #include <memory>
 
 #define EMIT_EVENT_0(name)                                       \
