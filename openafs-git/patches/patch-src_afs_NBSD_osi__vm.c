$NetBSD$

--- src/afs/NBSD/osi_vm.c.orig	2018-05-07 18:33:20.000000000 +0000
+++ src/afs/NBSD/osi_vm.c
@@ -79,7 +79,13 @@ osi_VM_StoreAllSegments(struct vcache *a
     ReleaseWriteLock(&avc->lock);
     AFS_GUNLOCK();
     vp = AFSTOV(avc);
-    mutex_enter(&vp->v_interlock);
+#ifdef AFS_NBSD70_ENV
+#define AMP
+#else
+#define AMP &
+#endif
+
+    mutex_enter(AMP vp->v_interlock);
     VOP_PUTPAGES(vp, 0, 0, PGO_ALLPAGES|PGO_CLEANIT|PGO_SYNCIO);
     AFS_GLOCK();
     ObtainWriteLock(&avc->lock, 94);
