$NetBSD$

Add namespace to isinf & isnan.

--- src/tidbits.cpp.orig	2025-03-29 23:54:39.595152947 +0000
+++ src/tidbits.cpp
@@ -1625,7 +1625,7 @@ int
 coin_isinf(double value)
 {
 #ifdef HAVE_ISINF
-  return isinf(value);
+  return std::isinf(value);
 #elif defined(HAVE_FPCLASS)
   if (fpclass(value) == FP_NINF) { return -1; }
   if (fpclass(value) == FP_PINF) { return +1; }
@@ -1653,7 +1653,7 @@ int
 coin_isnan(double value)
 {
 #ifdef HAVE_ISNAN
-  return isnan(value);
+  return std::isnan(value);
 #elif defined(HAVE__ISNAN)
   return _isnan(value);
 #elif defined(HAVE_FPCLASS)
