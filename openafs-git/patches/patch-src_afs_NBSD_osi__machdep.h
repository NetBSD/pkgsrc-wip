$NetBSD$

--- src/afs/NBSD/osi_machdep.h.orig	2018-05-07 18:33:20.000000000 +0000
+++ src/afs/NBSD/osi_machdep.h
@@ -52,7 +52,7 @@ typedef char * caddr_t;
 #define v_vfsp		v_mount
 
 /* vnode */
-#define VN_HOLD(vp)	(vget(vp, 0))
+#define VN_HOLD(vp)	(mutex_enter((vp)->v_interlock), vget((vp), 0))
 #define VN_RELE(vp)	(vrele(vp))
 #define osi_vnhold(avc, r) (VN_HOLD(AFSTOV(avc)))
 
