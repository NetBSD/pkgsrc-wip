$NetBSD$

Patch from NetBSD xsrc:
don't return void

--- src/gbm/backends/dri/gbm_dri.c.orig	2019-04-05 10:53:23.000000000 +0000
+++ src/gbm/backends/dri/gbm_dri.c
@@ -182,8 +182,13 @@ swrast_put_image(__DRIdrawable *driDrawa
                  char          *data,
                  void          *loaderPrivate)
 {
+#if defined(STRICT_XSRC_NETBSD)
+   swrast_put_image2(driDrawable, op, x, y, width, height,
+                     width * 4, data, loaderPrivate);
+#else
    return swrast_put_image2(driDrawable, op, x, y, width, height,
                             width * 4, data, loaderPrivate);
+#endif
 }
 
 static void
