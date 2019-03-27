$NetBSD$

--- src/gallium/drivers/llvmpipe/lp_setup_point.c.orig	2019-03-15 01:02:19.000000000 +0000
+++ src/gallium/drivers/llvmpipe/lp_setup_point.c
@@ -491,7 +491,11 @@ try_setup_point( struct lp_setup_context
    {
       struct lp_rast_plane *plane = GET_PLANES(point);
 
+#if defined(STRICT_XSRC_NETBSD)
+      plane[0].dcdx = ~0U << 8;
+#else
       plane[0].dcdx = -1 << 8;
+#endif
       plane[0].dcdy = 0;
       plane[0].c = (1-bbox.x0) << 8;
       plane[0].eo = 1 << 8;
@@ -507,7 +511,11 @@ try_setup_point( struct lp_setup_context
       plane[2].eo = 1 << 8;
 
       plane[3].dcdx = 0;
+#if defined(STRICT_XSRC_NETBSD)
+      plane[3].dcdy = ~0U << 8;
+#else
       plane[3].dcdy = -1 << 8;
+#endif
       plane[3].c = (bbox.y1+1) << 8;
       plane[3].eo = 0;
    }
