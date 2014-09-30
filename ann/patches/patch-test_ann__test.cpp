$NetBSD: patch-test_ann__test.cpp,v 1.1 2014/09/30 11:22:27 fhajny Exp $

Rename reserved symbol.
--- test/ann_test.cpp.orig	2010-01-28 04:40:01.000000000 +0000
+++ test/ann_test.cpp
@@ -281,7 +281,7 @@ using namespace std;					// make std:: a
 //------------------------------------------------------------------------
 
 const int		STRING_LEN		= 500;			// max string length
-const double	ERR				= 0.00001;		// epsilon (for float compares)
+const double	ANN_ERR				= 0.00001;		// epsilon (for float compares)
 const double	RND_OFF			= 5E-16;		// double round-off error
 
 //------------------------------------------------------------------------
@@ -1502,7 +1502,7 @@ void doValidation()						// perform vali
 												// reported i-th smallest
 			double rept_dist = ANN_ROOT(curr_apx_dst[j]);
 												// better than optimum?
-			if (rept_dist < true_dist*(1-ERR)) {
+			if (rept_dist < true_dist*(1-ANN_ERR)) {
 				Error("INTERNAL ERROR: True nearest neighbor incorrect",
 						ANNabort);
 			}
