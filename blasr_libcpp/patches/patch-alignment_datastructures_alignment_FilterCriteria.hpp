$NetBSD: patch-alignment_datastructures_alignment_FilterCriteria.hpp,v 1.1 2015/09/11 16:48:33 outpaddling Exp $

--- alignment/datastructures/alignment/FilterCriteria.hpp.orig	2015-08-12 17:41:23.000000000 +0000
+++ alignment/datastructures/alignment/FilterCriteria.hpp
@@ -39,7 +39,8 @@ public:
 private:
     float _value;
     ScoreSign _sign;
-    static constexpr float errorunit = 1e-6;
+    //static constexpr float errorunit = 1e-6;
+    float errorunit;
 };
 
 class HitPolicy {
