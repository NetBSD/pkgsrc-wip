$NetBSD$

# On NetBSD the stub drm_mode_create_lease_ioctl() always returns with -ENODEV,
  but after drmModeCreateLease() only allowed -EINVAL and -EOPNOTSUPP

--- render/allocator/allocator.c.orig	2025-12-04 16:11:21.906858096 +0000
+++ render/allocator/allocator.c
@@ -37,6 +37,7 @@ void wlr_allocator_init(struct wlr_alloc
  */
 static int reopen_drm_node(int drm_fd, bool allow_render_node) {
 	if (drmIsMaster(drm_fd)) {
+#if !defined(__NetBSD__)
 		// Only recent kernels support empty leases
 		uint32_t lessee_id;
 		int lease_fd = drmModeCreateLease(drm_fd, NULL, 0, O_CLOEXEC, &lessee_id);
@@ -46,6 +47,7 @@ static int reopen_drm_node(int drm_fd, b
 			wlr_log_errno(WLR_ERROR, "drmModeCreateLease failed");
 			return -1;
 		}
+#endif
 		wlr_log(WLR_DEBUG, "drmModeCreateLease failed, "
 			"falling back to plain open");
 	}
