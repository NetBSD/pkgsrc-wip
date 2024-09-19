$NetBSD$

WITH_GETLINE patch from FreeBSD ports x11-drivers/xf86-video-intel

Patch for --enable-debug from DragonFly dports
x11-drivers/xf86-video-intel29 

Additional patch for DragonFly because struct drm_i915_gem_mmap
has a field flags.

https://bz-attachments.freebsd.org/attachment.cgi?id=20233

Fix SNA for drm-v4.11 or later by disabling I915_USERPTR_UNSYNCHRONIZED

I915_USERPTR_UNSYNCHRONIZED is broken since drm-v4.11
https://github.com/FreeBSDDesktop/kms-drm/issues/32

--- src/sna/kgem.c.orig	2019-03-01 18:22:07.000000000 +0000
+++ src/sna/kgem.c
@@ -29,6 +29,11 @@
 #include "config.h"
 #endif
 
+#if defined(__FreeBSD__)
+#define _WITH_GETLINE	/* to expose getline() in stdio.h on FreeBSD */
+#include <stdio.h>	/* for getline() */
+#endif
+
 #include "sna.h"
 #include "sna_reg.h"
 
@@ -69,9 +74,17 @@ search_snoop_cache(struct kgem *kgem, un
 #define DBG_NO_CPU 0
 #define DBG_NO_CREATE2 0
 #define DBG_NO_USERPTR 0
+#if defined(SET_DBG_NO_UNSYNCHRONIZED_USERPTR)
+#define DBG_NO_UNSYNCHRONIZED_USERPTR 1
+#else
 #define DBG_NO_UNSYNCHRONIZED_USERPTR 0
+#endif
 #define DBG_NO_COHERENT_MMAP_GTT 0
+#if defined(SET_DBG_NO_LLC)
+#define DBG_NO_LLC 1
+#else
 #define DBG_NO_LLC 0
+#endif
 #define DBG_NO_SEMAPHORES 0
 #define DBG_NO_MADV 0
 #define DBG_NO_UPLOAD_CACHE 0
@@ -682,7 +695,11 @@ retry_wc:
 
 static void *__kgem_bo_map__cpu(struct kgem *kgem, struct kgem_bo *bo)
 {
+#if defined(__DragonFly__)
+	struct local_i915_gem_mmap2 arg;
+#else
 	struct local_i915_gem_mmap arg;
+#endif
 	int err;
 
 	VG_CLEAR(arg);
@@ -691,7 +708,12 @@ static void *__kgem_bo_map__cpu(struct k
 retry:
 	arg.handle = bo->handle;
 	arg.size = bytes(bo);
+#if defined(__DragonFly__)
+	arg.flags = 0;
+	if ((err = do_ioctl(kgem->fd, LOCAL_IOCTL_I915_GEM_MMAP_v2, &arg))) {
+#else
 	if ((err = do_ioctl(kgem->fd, LOCAL_IOCTL_I915_GEM_MMAP, &arg))) {
+#endif
 		DBG(("%s: failed %d, throttling/cleaning caches\n",
 		     __FUNCTION__, err));
 		assert(err != -EINVAL || bo->prime);
@@ -3313,11 +3335,21 @@ bool __kgem_ring_is_idle(struct kgem *kg
 	if (rq) {
 		struct kgem_request *tmp;
 
+#if defined(KGEM_NULL_BO)
+		if (rq->bo == NULL)
+			fprintf(stderr, "__kgem_ring_is_idle: rq->bo == NULL\n");
+		if (rq->bo && __kgem_busy(kgem, rq->bo->handle)) {
+			DBG(("%s: last fence handle=%d still busy\n",
+			     __FUNCTION__, rq->bo->handle));
+			return false;
+		}
+#else
 		if (__kgem_busy(kgem, rq->bo->handle)) {
 			DBG(("%s: last fence handle=%d still busy\n",
 			     __FUNCTION__, rq->bo->handle));
 			return false;
 		}
+#endif
 
 		do {
 			tmp = list_first_entry(&kgem->requests[ring],
