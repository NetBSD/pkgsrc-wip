$NetBSD$

WITH_GETLINE patch from FreeBSD ports libdrm 2.4.75.

Patch for --enable-debug from DragonFly dports
x11-drivers/xf86-video-intel29 

Additional patch for DragonFly because struct drm_i915_gem_mmap
has a field flags.

--- src/sna/kgem.c.orig	2017-02-10 21:52:47.000000000 +0000
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
 
@@ -70,7 +75,11 @@ search_snoop_cache(struct kgem *kgem, un
 #define DBG_NO_CREATE2 0
 #define DBG_NO_USERPTR 0
 #define DBG_NO_UNSYNCHRONIZED_USERPTR 0
+#if defined(__DragonFly__)
+#define DBG_NO_LLC 1
+#else
 #define DBG_NO_LLC 0
+#endif
 #define DBG_NO_SEMAPHORES 0
 #define DBG_NO_MADV 0
 #define DBG_NO_UPLOAD_CACHE 0
@@ -680,7 +689,11 @@ retry_wc:
 
 static void *__kgem_bo_map__cpu(struct kgem *kgem, struct kgem_bo *bo)
 {
+#if defined(__DragonFly__)
+	struct local_i915_gem_mmap2 arg;
+#else
 	struct local_i915_gem_mmap arg;
+#endif
 	int err;
 
 	VG_CLEAR(arg);
@@ -689,7 +702,12 @@ static void *__kgem_bo_map__cpu(struct k
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
@@ -3299,11 +3317,21 @@ bool __kgem_ring_is_idle(struct kgem *kg
 	if (rq) {
 		struct kgem_request *tmp;
 
+#if defined(__DragonFly__)
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
