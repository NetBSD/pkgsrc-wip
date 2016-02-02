$NetBSD$

Changes for compiling with Qt5 instead of Qt4

--- libgui/qterminal/libqterminal/unix/konsole_wcwidth.h.orig	2015-05-23 14:21:53.000000000 +0000
+++ libgui/qterminal/libqterminal/unix/konsole_wcwidth.h
@@ -11,7 +11,6 @@
 #define	_KONSOLE_WCWIDTH_H_
 
 // Qt
-#include <QtCore/QBool>
 #include <QtCore/QString>
 
 int konsole_wcwidth(quint16 ucs);
