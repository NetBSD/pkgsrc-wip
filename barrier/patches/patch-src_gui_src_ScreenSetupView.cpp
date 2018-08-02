$NetBSD$

--- src/gui/src/ScreenSetupView.cpp.orig	2018-05-16 02:48:18.000000000 +0000
+++ src/gui/src/ScreenSetupView.cpp
@@ -22,6 +22,7 @@
 
 #include <QtCore>
 #include <QtGui>
+#include <QHeaderView>
 
 ScreenSetupView::ScreenSetupView(QWidget* parent) :
     QTableView(parent)
