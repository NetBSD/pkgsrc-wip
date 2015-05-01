$NetBSD: patch-modules_gui_qt4_input__manager.hpp,v 1.1 2015/05/01 06:24:13 idleroux Exp $

--- modules/gui/qt4/input_manager.hpp.orig	2015-01-26 18:50:20.000000000 +0000
+++ modules/gui/qt4/input_manager.hpp
@@ -37,6 +37,7 @@
 
 #include <QObject>
 #include <QEvent>
+typedef int64_t putime_t;
 class QSignalMapper;
 
 enum { NORMAL,    /* loop: 0, repeat: 0 */
@@ -212,11 +213,11 @@ public slots:
     void setAtoB();
 
 private slots:
-    void AtoBLoop( float, int64_t, int );
+    void AtoBLoop( float, putime_t, int );
 
 signals:
     /// Send new position, new time and new length
-    void positionUpdated( float , int64_t, int );
+    void positionUpdated( float , putime_t, int );
     void seekRequested( float pos );
     void rateChanged( float );
     void nameChanged( const QString& );
