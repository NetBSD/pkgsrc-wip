$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/libdrm/src/xf86drmMode.c.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/libdrm/src/xf86drmMode.c
@@ -976,7 +976,7 @@ drm_public int drmCheckModesettingSuppor
 	}
 #elif defined(__DragonFly__)
 	return 0;
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
 	int	fd;
 	struct drm_mode_card_res res;
 	drmModeResPtr r = 0;
@@ -1129,7 +1129,11 @@ drm_public int drmModePageFlipTarget(int
 
 drm_public int drmModeSetPlane(int fd, uint32_t plane_id, uint32_t crtc_id,
 		    uint32_t fb_id, uint32_t flags,
+#if defined(__NetBSD__)
+			uint32_t crtc_x, uint32_t crtc_y,
+#else
 		    int32_t crtc_x, int32_t crtc_y,
+#endif
 		    uint32_t crtc_w, uint32_t crtc_h,
 		    uint32_t src_x, uint32_t src_y,
 		    uint32_t src_w, uint32_t src_h)
