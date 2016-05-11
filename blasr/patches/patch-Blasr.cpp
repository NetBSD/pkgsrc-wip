$NetBSD$
# Replce C++11ism

--- Blasr.cpp.orig	2015-08-13 20:42:14.000000000 +0000
+++ Blasr.cpp
@@ -2655,9 +2655,12 @@ SelectAlignmentsToPrint(vector<T_Alignme
   // Apply filter criteria and hit policy.
   // Shallow copy AlignmentCandidate pointers.
   vector<T_AlignmentCandidate*> filtered;
-  for (auto ptr: alignmentPtrs) {
-      if (params.filterCriteria.Satisfy(ptr)) {
-          filtered.push_back(ptr);
+  // for (auto ptr: alignmentPtrs) {
+  //    if (params.filterCriteria.Satisfy(ptr)) {
+  //        filtered.push_back(ptr);
+  for (int i = 0; i < alignmentPtrs.size(); ++i) {
+      if (params.filterCriteria.Satisfy(alignmentPtrs[i])) {
+          filtered.push_back(alignmentPtrs[i]);
           if (filtered.size() == params.nBest) break;
       }
   }
