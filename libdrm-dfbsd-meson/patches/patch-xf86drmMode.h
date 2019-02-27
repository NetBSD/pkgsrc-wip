$NetBSD: patch-xf86drmMode.h,v 1.1 2014/10/26 10:20:10 wiz Exp $

FreeBSD ports / DragonFly dports does not have patch for drmModeSetPlane.
Android deliberately uses signed crtc_x and crtc_y
"to allow a destination location that is partially off screen."

--- xf86drmMode.h.orig	2014-06-14 12:33:26.000000000 +0000
+++ xf86drmMode.h
@@ -485,7 +485,11 @@ extern drmModePlaneResPtr drmModeGetPlan
 extern drmModePlanePtr drmModeGetPlane(int fd, uint32_t plane_id);
 extern int drmModeSetPlane(int fd, uint32_t plane_id, uint32_t crtc_id,
 			   uint32_t fb_id, uint32_t flags,
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
+			   uint32_t crtc_x, uint32_t crtc_y,
+#else
 			   int32_t crtc_x, int32_t crtc_y,
+#endif
 			   uint32_t crtc_w, uint32_t crtc_h,
 			   uint32_t src_x, uint32_t src_y,
 			   uint32_t src_w, uint32_t src_h);
