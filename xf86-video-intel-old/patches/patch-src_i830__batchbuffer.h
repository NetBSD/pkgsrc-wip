$NetBSD: patch-src_i830__batchbuffer.h,v 1.1 2013/05/29 03:38:09 makoto Exp $

--- src/i830_batchbuffer.h.orig	2009-05-13 00:12:11.000000000 +0000
+++ src/i830_batchbuffer.h
@@ -56,7 +56,7 @@ intel_batch_start_atomic(ScrnInfoPtr pSc
     I830Ptr pI830 = I830PTR(pScrn);
 
     assert(!pI830->in_batch_atomic);
-    intel_batch_require_space(pScrn, pI830, sz * 4);
+    intel_batch_require_space(pScrn, pI830, sz);
 
     pI830->in_batch_atomic = TRUE;
     pI830->batch_atomic_limit = pI830->batch_used + sz * 4;
