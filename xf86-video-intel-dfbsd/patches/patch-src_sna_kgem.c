$NetBSD$

From DragonFly dports x11-drivers/xf86-video-intel29

--- src/sna/kgem.c.orig	2014-12-09 16:08:21.000000000 +0000
+++ src/sna/kgem.c
@@ -70,7 +70,11 @@ search_snoop_cache(struct kgem *kgem, un
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
@@ -2802,11 +2806,21 @@ bool __kgem_ring_is_idle(struct kgem *kg
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
