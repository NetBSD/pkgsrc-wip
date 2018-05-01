$NetBSD: patch-radeon_radeon__bo__gem.c,v 1.1 2014/10/26 10:20:10 wiz Exp $

FreeBSD ports / DragonFly dports does not have this patch.

--- radeon/radeon_bo_gem.c.orig	2017-11-03 16:44:27.000000000 +0000
+++ radeon/radeon_bo_gem.c
@@ -178,8 +178,13 @@ static int bo_map(struct radeon_bo_int *
                 boi, boi->handle, r);
         return r;
     }
+#if defined(__FreeBSD__) || defined(__DragonFly__)
     ptr = drm_mmap(0, args.size, PROT_READ|PROT_WRITE, MAP_SHARED, boi->bom->fd, args.addr_ptr);
     if (ptr == MAP_FAILED)
+#else
+    r = drmMap(boi->bom->fd, args.addr_ptr, args.size, &ptr);
+    if (r)
+#endif
         return -errno;
     bo_gem->priv_ptr = ptr;
 wait:
@@ -252,9 +257,16 @@ static int bo_set_tiling(struct radeon_b
 static int bo_get_tiling(struct radeon_bo_int *boi, uint32_t *tiling_flags,
                          uint32_t *pitch)
 {
+#if defined(__FreeBSD__) || defined(__DragonFly__)
     struct drm_radeon_gem_set_tiling args = {};
+#else
+    struct drm_radeon_gem_set_tiling args;
+#endif
     int r;
 
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
+    memset(&args, 0, sizeof args);
+#endif
     args.handle = boi->handle;
 
     r = drmCommandWriteRead(boi->bom->fd,
