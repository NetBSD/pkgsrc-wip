$NetBSD$

--- glx/glxdrawable.h.orig	2019-02-26 19:28:50.000000000 +0000
+++ glx/glxdrawable.h
@@ -53,6 +53,9 @@ struct __GLXdrawable {
 
     DrawablePtr pDraw;
     XID drawId;
+#if defined(OTHERID_XSRC_NETBSD)
+    XID otherId; /* for glx1.3 we need to track the original Drawable as well */
+#endif
 
     /*
      ** Either GLX_DRAWABLE_PIXMAP, GLX_DRAWABLE_WINDOW or
