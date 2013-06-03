$NetBSD: patch-src_third__party_s2_s2.cc,v 1.1 2013/06/03 13:58:35 fhajny Exp $

Avoid ambiguous overload.
--- src/third_party/s2/s2.cc.orig	2013-04-23 12:55:09.000000000 +0000
+++ src/third_party/s2/s2.cc
@@ -699,8 +699,8 @@ S2::LengthMetric const S2::kAvgAngleSpan
 
 S2::LengthMetric const S2::kMinWidth(
     S2_PROJECTION == S2_LINEAR_PROJECTION ? sqrt(2. / 3) :             // 0.816
-    S2_PROJECTION == S2_TAN_PROJECTION ? M_PI / (2 * sqrt(2)) :        // 1.111
-    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 2 * sqrt(2) / 3 :       // 0.943
+    S2_PROJECTION == S2_TAN_PROJECTION ? M_PI / (2 * sqrt((double)2)) :        // 1.111
+    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 2 * sqrt((double)2) / 3 :       // 0.943
     0);
 
 S2::LengthMetric const S2::kMaxWidth(S2::kMaxAngleSpan.deriv());
@@ -713,9 +713,9 @@ S2::LengthMetric const S2::kAvgWidth(
     0);
 
 S2::LengthMetric const S2::kMinEdge(
-    S2_PROJECTION == S2_LINEAR_PROJECTION ? 2 * sqrt(2) / 3 :          // 0.943
-    S2_PROJECTION == S2_TAN_PROJECTION ? M_PI / (2 * sqrt(2)) :        // 1.111
-    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 2 * sqrt(2) / 3 :       // 0.943
+    S2_PROJECTION == S2_LINEAR_PROJECTION ? 2 * sqrt((double)2) / 3 :          // 0.943
+    S2_PROJECTION == S2_TAN_PROJECTION ? M_PI / (2 * sqrt((double)2)) :        // 1.111
+    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 2 * sqrt((double)2) / 3 :       // 0.943
     0);
 
 S2::LengthMetric const S2::kMaxEdge(S2::kMaxAngleSpan.deriv());
@@ -728,14 +728,14 @@ S2::LengthMetric const S2::kAvgEdge(
     0);
 
 S2::LengthMetric const S2::kMinDiag(
-    S2_PROJECTION == S2_LINEAR_PROJECTION ? 2 * sqrt(2) / 3 :          // 0.943
-    S2_PROJECTION == S2_TAN_PROJECTION ? M_PI * sqrt(2) / 3 :          // 1.481
-    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 8 * sqrt(2) / 9 :       // 1.257
+    S2_PROJECTION == S2_LINEAR_PROJECTION ? 2 * sqrt((double)2) / 3 :          // 0.943
+    S2_PROJECTION == S2_TAN_PROJECTION ? M_PI * sqrt((double)2) / 3 :          // 1.481
+    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 8 * sqrt((double)2) / 9 :       // 1.257
     0);
 
 S2::LengthMetric const S2::kMaxDiag(
-    S2_PROJECTION == S2_LINEAR_PROJECTION ? 2 * sqrt(2) :              // 2.828
-    S2_PROJECTION == S2_TAN_PROJECTION ? M_PI * sqrt(2. / 3) :         // 2.565
+    S2_PROJECTION == S2_LINEAR_PROJECTION ? 2 * sqrt((double)2) :              // 2.828
+    S2_PROJECTION == S2_TAN_PROJECTION ? M_PI * sqrt((double)2. / 3) :         // 2.565
     S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 2.438654594434021032 :  // 2.439
     0);
 
@@ -746,9 +746,9 @@ S2::LengthMetric const S2::kAvgDiag(
     0);
 
 S2::AreaMetric const S2::kMinArea(
-    S2_PROJECTION == S2_LINEAR_PROJECTION ? 4 / (3 * sqrt(3)) :        // 0.770
-    S2_PROJECTION == S2_TAN_PROJECTION ? (M_PI*M_PI) / (4*sqrt(2)) :   // 1.745
-    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 8 * sqrt(2) / 9 :       // 1.257
+    S2_PROJECTION == S2_LINEAR_PROJECTION ? 4 / (3 * sqrt((double)3)) :        // 0.770
+    S2_PROJECTION == S2_TAN_PROJECTION ? (M_PI*M_PI) / (4*sqrt((double)2)) :   // 1.745
+    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 8 * sqrt((double)2) / 9 :       // 1.257
     0);
 
 S2::AreaMetric const S2::kMaxArea(
@@ -761,10 +761,10 @@ S2::AreaMetric const S2::kAvgArea(4 * M_
 // This is true for all projections.
 
 double const S2::kMaxEdgeAspect = (
-    S2_PROJECTION == S2_LINEAR_PROJECTION ? sqrt(2) :                  // 1.414
-    S2_PROJECTION == S2_TAN_PROJECTION ?  sqrt(2) :                    // 1.414
+    S2_PROJECTION == S2_LINEAR_PROJECTION ? sqrt((double)2) :                  // 1.414
+    S2_PROJECTION == S2_TAN_PROJECTION ?  sqrt((double)2) :                    // 1.414
     S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 1.442615274452682920 :  // 1.443
     0);
 
-double const S2::kMaxDiagAspect = sqrt(3);                             // 1.732
+double const S2::kMaxDiagAspect = sqrt((double)3);                             // 1.732
 // This is true for all projections.
