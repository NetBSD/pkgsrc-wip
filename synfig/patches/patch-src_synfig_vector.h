$NetBSD: patch-src_synfig_vector.h,v 1.1 2011/03/22 10:14:08 phonohawk Exp $

Fix build breakage (I'm not sure this patch is appropriate though.)

--- src/synfig/vector.h.orig	2011-03-22 09:08:55.000000000 +0000
+++ src/synfig/vector.h
@@ -52,6 +52,8 @@ extern "C" { int _isnan(double x); }
 inline bool isnan(double x) { return x != x; }
 inline bool isnan(float x) { return x != x; }
 #define SYNFIG_ISNAN_FIX 1
+#else
+#define isnan std::isnan
 #endif
 
 
