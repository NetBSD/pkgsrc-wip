$NetBSD$

Fix build with devel/c++gsl verison 4.0.0

--- src/Tags.cpp.orig	2020-02-05 05:36:17.000000000 +0000
+++ src/Tags.cpp
@@ -11,7 +11,8 @@
 #include "Util/Input.h"
 #include "Util/User.h"
 
-#include <gsl/gsl_util>
+#include <gsl/narrow>
+#include <gsl/util>
 
 #include <QApplication>
 #include <QDir>
