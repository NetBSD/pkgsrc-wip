$NetBSD$

--- src/gbm/backends/dri/gbm_dri.c.orig	2019-03-06 23:05:20.000000000 +0000
+++ src/gbm/backends/dri/gbm_dri.c
@@ -302,7 +302,11 @@ dri_open_driver(struct gbm_dri_device *d
    /* XXX: Library name differs on per platforms basis. Update this as
     * osx/cygwin/windows/bsd gets support for GBM..
     */
+#if defined(SO_NAME_OPENBSD)
+   dlopen("libglapi.so", RTLD_LAZY | RTLD_GLOBAL);
+#else
    dlopen("libglapi.so.0", RTLD_LAZY | RTLD_GLOBAL);
+#endif
 
    static const char *search_path_vars[] = {
       /* Read GBM_DRIVERS_PATH first for compatibility, but LIBGL_DRIVERS_PATH
