$NetBSD$

Fix build with devel/c++gsl verison 4.0.0

--- Util/Resource.cpp.orig	2020-02-05 05:36:17.000000000 +0000
+++ Util/Resource.cpp
@@ -1,7 +1,8 @@
 
 #include "Util/Resource.h"
 
-#include <gsl/gsl_util>
+#include <gsl/narrow>
+#include <gsl/util>
 
 #include <QByteArray>
 #include <QResource>
