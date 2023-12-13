$NetBSD$

Fix build with devel/c++gsl verison 4.0.0

--- src/shift.cpp.orig	2020-02-05 05:36:17.000000000 +0000
+++ src/shift.cpp
@@ -6,7 +6,8 @@
 #include "Util/algorithm.h"
 #include "Util/string_view.h"
 
-#include <gsl/gsl_util>
+#include <gsl/narrow>
+#include <gsl/util>
 
 namespace {
 
