$NetBSD: patch-src_bundles.cpp,v 1.1 2014/09/04 21:51:02 outpaddling Exp $

# Const too big for int on some systems
--- src/bundles.cpp.orig	2014-03-24 21:54:47.000000000 +0000
+++ src/bundles.cpp
@@ -698,7 +698,7 @@ double BundleFactory::next_valid_alignme
         if (!_hit_fac->get_hit_from_buf(hit_buf, tmp, false))
             continue;
         
-		if (tmp.ref_id() == 12638153115695167477)  // corresponds to SAM "*" under FNV hash. unaligned read record 
+		if (tmp.ref_id() == 12638153115695167477ULL)  // corresponds to SAM "*" under FNV hash. unaligned read record 
             continue;
         
 		raw_mass += tmp.mass();
