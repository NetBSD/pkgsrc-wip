$NetBSD$

--- glx/glxcmds.c.orig	2019-02-26 19:28:50.000000000 +0000
+++ glx/glxcmds.c
@@ -1137,6 +1137,9 @@ __glXDrawableInit(__GLXdrawable * drawab
     drawable->pDraw = pDraw;
     drawable->type = type;
     drawable->drawId = drawId;
+#if defined(OTHERID_XSRC_NETBSD)
+    drawable->otherId = 0;
+#endif
     drawable->config = config;
     drawable->eventMask = 0;
 
