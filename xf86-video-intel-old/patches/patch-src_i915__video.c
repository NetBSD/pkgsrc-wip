$NetBSD: patch-src_i915__video.c,v 1.1 2013/05/29 03:38:09 makoto Exp $

git clone git://cgit.freedesktop.org/xorg/driver/xf86-video-intel/
git checkout e4cd9de2933ada3e2a4b43552729ae3a370128bf
and make diff

--- src/i915_video.c.orig	2009-05-13 00:12:11.000000000 +0000
+++ src/i915_video.c
@@ -50,8 +50,7 @@ I915DisplayVideoTextured(ScrnInfoPtr pSc
    I830Ptr pI830 = I830PTR(pScrn);
    uint32_t format, ms3, s5;
    BoxPtr pbox = REGION_RECTS(dstRegion);
-   int nbox_total = REGION_NUM_RECTS(dstRegion);
-   int nbox_this_time;
+   int nbox = REGION_NUM_RECTS(dstRegion);
    int dxo, dyo, pix_xoff, pix_yoff;
    Bool planar;
 
@@ -74,17 +73,7 @@ I915DisplayVideoTextured(ScrnInfoPtr pSc
       return;
    }
 
-#define BYTES_FOR_BOXES(n)	((200 + (n) * 20) * 4)
-#define BOXES_IN_BYTES(s)	((((s)/4) - 200) / 20)
-#define BATCH_BYTES(p)		((p)->batch_bo->size - 16)
-
-   while (nbox_total) {
-	nbox_this_time = nbox_total;
-	if (BYTES_FOR_BOXES(nbox_this_time) > BATCH_BYTES(pI830))
-		nbox_this_time = BOXES_IN_BYTES(BATCH_BYTES(pI830));
-	nbox_total -= nbox_this_time;
-
-   intel_batch_start_atomic(pScrn, 200 + 20 * nbox_this_time);
+   intel_batch_start_atomic(pScrn, 200 + 20 * nbox);
 
    IntelEmitInvarientState(pScrn);
    pI830->last_3d = LAST_3D_VIDEO;
@@ -377,7 +366,7 @@ I915DisplayVideoTextured(ScrnInfoPtr pSc
    dxo = dstRegion->extents.x1;
    dyo = dstRegion->extents.y1;
 
-   while (nbox_this_time--)
+   while (nbox--)
    {
       int box_x1 = pbox->x1;
       int box_y1 = pbox->y1;
@@ -426,7 +415,6 @@ I915DisplayVideoTextured(ScrnInfoPtr pSc
    }
 
    intel_batch_end_atomic(pScrn);
-   }
 
    i830MarkSync(pScrn);
 }
