$NetBSD$

Add missing include.

--- librecad/src/ui/forms/qg_commandwidget.cpp.orig	2018-02-15 20:54:45.000000000 +0000
+++ librecad/src/ui/forms/qg_commandwidget.cpp
@@ -27,6 +27,7 @@
 
 #include <algorithm>
 
+#include <QAction>
 #include <QKeyEvent>
 #include <QFileDialog>
 #include <QSettings>
