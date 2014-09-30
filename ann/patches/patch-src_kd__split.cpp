$NetBSD: patch-src_kd__split.cpp,v 1.1 2014/09/30 11:22:27 fhajny Exp $

Rename reserved symbol.
--- src/kd_split.cpp.orig	2010-01-28 04:40:01.000000000 +0000
+++ src/kd_split.cpp
@@ -31,7 +31,7 @@
 //	Constants
 //----------------------------------------------------------------------
 
-const double ERR = 0.001;				// a small value
+const double ANN_ERR = 0.001;				// a small value
 const double FS_ASPECT_RATIO = 3.0;		// maximum allowed aspect ratio
 										// in fair split. Must be >= 2.
 
@@ -95,7 +95,7 @@ void midpt_split(
 	ANNcoord max_spread = -1;			// find long side with most spread
 	for (d = 0; d < dim; d++) {
 										// is it among longest?
-		if (double(bnds.hi[d] - bnds.lo[d]) >= (1-ERR)*max_length) {
+		if (double(bnds.hi[d] - bnds.lo[d]) >= (1-ANN_ERR)*max_length) {
 										// compute its spread
 			ANNcoord spr = annSpread(pa, pidx, n, d);
 			if (spr > max_spread) {		// is it max so far?
@@ -165,7 +165,7 @@ void sl_midpt_split(
 	ANNcoord max_spread = -1;			// find long side with most spread
 	for (d = 0; d < dim; d++) {
 										// is it among longest?
-		if ((bnds.hi[d] - bnds.lo[d]) >= (1-ERR)*max_length) {
+		if ((bnds.hi[d] - bnds.lo[d]) >= (1-ANN_ERR)*max_length) {
 										// compute its spread
 			ANNcoord spr = annSpread(pa, pidx, n, d);
 			if (spr > max_spread) {		// is it max so far?
