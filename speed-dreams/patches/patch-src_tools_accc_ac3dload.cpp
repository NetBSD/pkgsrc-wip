$NetBSD$

--- src/tools/accc/ac3dload.cpp.orig	2022-07-28 18:09:03.923596511 -0700
+++ src/tools/accc/ac3dload.cpp	2022-07-28 18:09:20.308494481 -0700
@@ -576,7 +576,7 @@
     norm->y = (p3 * q1 - q3 * p1) / dd;
     norm->z = (p1 * q2 - q1 * p2) / dd;
 
-    if (isnan(norm->x) || isnan(norm->y) || isnan(norm->z))
+    if (std::isnan(norm->x) || std::isnan(norm->y) || std::isnan(norm->z))
     {
         norm->x = 0;
         norm->y = 1.0;
