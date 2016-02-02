$NetBSD$

Changes for compiling with Qt5 instead of Qt4

--- libgui/qterminal/libqterminal/unix/TerminalView.cpp.orig	2015-05-23 14:21:53.000000000 +0000
+++ libgui/qterminal/libqterminal/unix/TerminalView.cpp
@@ -41,6 +41,7 @@
 #include <QPixmap>
 #include <QScrollBar>
 #include <QStyle>
+#include <QToolTip>
 #include <QtCore>
 #include <QtGui>
 
