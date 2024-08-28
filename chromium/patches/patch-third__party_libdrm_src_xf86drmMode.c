$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libdrm/src/xf86drmMode.c.orig	2024-08-21 22:48:07.003577700 +0000
+++ third_party/libdrm/src/xf86drmMode.c
@@ -966,7 +966,7 @@ drm_public int drmCheckModesettingSuppor
 	}
 #elif defined(__DragonFly__)
 	return 0;
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
 	int	fd;
 	struct drm_mode_card_res res;
 	drmModeResPtr r = 0;
@@ -1119,7 +1119,11 @@ drm_public int drmModePageFlipTarget(int
 
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
