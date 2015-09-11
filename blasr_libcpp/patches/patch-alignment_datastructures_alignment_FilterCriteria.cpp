$NetBSD: patch-alignment_datastructures_alignment_FilterCriteria.cpp,v 1.1 2015/09/11 16:48:33 outpaddling Exp $

--- alignment/datastructures/alignment/FilterCriteria.cpp.orig	2015-08-12 17:41:23.000000000 +0000
+++ alignment/datastructures/alignment/FilterCriteria.cpp
@@ -21,12 +21,12 @@
 Score::Score(const float & value, const ScoreSign & sign)
     : _value(value)
     , _sign(sign)
-{ }
+{ errorunit = 1e-6; }
 
 Score::Score(const Score & another) 
     : _value(another._value)
     , _sign(another._sign)
-{ }
+{ errorunit = 1e-6; }
 
 Score::~Score() { }
 
@@ -144,9 +144,18 @@ HitPolicy::Apply(const std::vector<T_Ali
     // Assume that input alignments share the same query name and
     // are sorted by score and tPos asscendingly: worst, ...., best
     int bestScore = ret[0]->score;
+
+    /* Not sure how to convert this.  C++11ism?
     ret.erase(std::remove_if(ret.begin(), ret.end(),
               [&bestScore](const T_AlignmentCandidate* x)->bool{return x->score != bestScore;}),
               ret.end());
+    */
+
+    // Attempt to replace lambda function.  Double check this...
+    std::vector<T_AlignmentCandidate *>::iterator i = ret.begin();
+    while ( (*i)->score == bestScore )
+	++i;
+    ret.erase( i, ret.end() );
 
     if (IsAllbest()) {
         return ret;
@@ -267,18 +276,23 @@ const std::string FilterCriteria::Help(c
                         pad + scoreCutoffHelp());
 }*/
 
+// FIXME: Strange error from CentOS 6.7 g++ 4.4:
+// /home/bacon/blasr_libcpp/branches/c++0x/alignment/datastructures/alignment/FilterCriteria.cpp:285: error: call of overloaded to_string(int) is ambiguous
+// /usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/basic_string.h:2604: note: candidates are: std::string std::to_string(long long int)
+// /usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/basic_string.h:2610: note:                 std::string std::to_string(long long unsigned int)
+// /usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/basic_string.h:2616: note:                 std::string std::to_string(long double)
 const std::string FilterCriteria::MinAlnLengthHelp() {
-    return std::string("(") + std::to_string(_minAlnLength) + ") " +
+    return std::string("(") + std::to_string(static_cast<long long>(_minAlnLength)) + ") " +
            "Report alignments only if their lengths are greater than minAlnLength.";
 }
 
 const std::string FilterCriteria::MinPctSimilarityHelp() {
-    return std::string("(") + std::to_string(static_cast<int>(_minPctSimilarity)) + ") " +
+    return std::string("(") + std::to_string(static_cast<long long>(_minPctSimilarity)) + ") " +
            "Report alignments only if their percentage similairty is greater than minPctSimilarity.";
 }
 
 const std::string FilterCriteria::MinPctAccuracyHelp() {
-    return std::string("(") + std::to_string(static_cast<int>(_minPctAccuracy)) + ") " + 
+    return std::string("(") + std::to_string(static_cast<long long>(_minPctAccuracy)) + ") " + 
            "Report alignments only if their percentage accuray is greater than minAccuracy.";
 }
 
