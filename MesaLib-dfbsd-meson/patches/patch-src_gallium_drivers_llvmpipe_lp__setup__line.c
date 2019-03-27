$NetBSD$

--- src/gallium/drivers/llvmpipe/lp_setup_line.c.orig	2019-03-15 01:02:19.000000000 +0000
+++ src/gallium/drivers/llvmpipe/lp_setup_line.c
@@ -724,7 +724,11 @@ try_setup_line( struct lp_setup_context 
       struct lp_rast_plane *plane_s = &plane[4];
 
       if (s_planes[0]) {
+#if defined(STRICT_XSRC_NETBSD)
+         plane_s->dcdx = ~0U << 8;
+#else
          plane_s->dcdx = -1 << 8;
+#endif
          plane_s->dcdy = 0;
          plane_s->c = (1-scissor->x0) << 8;
          plane_s->eo = 1 << 8;
@@ -746,7 +750,11 @@ try_setup_line( struct lp_setup_context 
       }
       if (s_planes[3]) {
          plane_s->dcdx = 0;
+#if defined(STRICT_XSRC_NETBSD)
+         plane_s->dcdy = ~0U << 8;
+#else
          plane_s->dcdy = -1 << 8;
+#endif
          plane_s->c = (scissor->y1+1) << 8;
          plane_s->eo = 0;
          plane_s++;
