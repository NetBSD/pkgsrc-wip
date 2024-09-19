$NetBSD$

--- glx/glxext.c.orig	2019-02-26 19:28:50.000000000 +0000
+++ glx/glxext.c
@@ -97,6 +97,20 @@ DrawableGone(__GLXdrawable * glxPriv, XI
 {
     __GLXcontext *c, *next;
 
+#if defined(OTHERID_XSRC_NETBSD)
+    if (glxPriv->type == GLX_DRAWABLE_WINDOW || glxPriv->type == GLX_DRAWABLE_PIXMAP) {
+        /* If this was created by glXCreateWindow, free the matching resource */
+        if (glxPriv->otherId) {
+            XID other = glxPriv->otherId;
+            glxPriv->otherId = 0;
+            if (xid == other)
+                FreeResourceByType(glxPriv->drawId, __glXDrawableRes, TRUE);
+            else
+                FreeResourceByType(other, __glXDrawableRes, TRUE);
+        }
+        /* otherwise this window was implicitly created by MakeCurrent */
+    }
+#else
     if (glxPriv->type == GLX_DRAWABLE_WINDOW) {
         /* If this was created by glXCreateWindow, free the matching resource */
         if (glxPriv->drawId != glxPriv->pDraw->id) {
@@ -107,6 +121,7 @@ DrawableGone(__GLXdrawable * glxPriv, XI
         }
         /* otherwise this window was implicitly created by MakeCurrent */
     }
+#endif
 
     for (c = glxAllContexts; c; c = next) {
         next = c->next;
