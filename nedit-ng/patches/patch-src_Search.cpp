$NetBSD$

Fix build with devel/c++gsl verison 4.0.0

--- src/Search.cpp.orig	2020-02-05 05:36:17.000000000 +0000
+++ src/Search.cpp
@@ -13,7 +13,8 @@
 #include "WrapStyle.h"
 #include "userCmds.h"
 
-#include <gsl/gsl_util>
+#include <gsl/narrow>
+#include <gsl/util>
 
 #include <algorithm>
 #include <cctype>
