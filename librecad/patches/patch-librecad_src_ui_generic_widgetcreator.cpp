$NetBSD$

Add missing includes.

--- librecad/src/ui/generic/widgetcreator.cpp.orig	2018-02-15 20:54:45.000000000 +0000
+++ librecad/src/ui/generic/widgetcreator.cpp
@@ -27,6 +27,8 @@
 #include "widgetcreator.h"
 #include "ui_widgetcreator.h"
 
+#include <QAction>
+#include <QActionGroup>
 #include <QSettings>
 #include <QLineEdit>
 #include <QPushButton>
