$NetBSD$

netbsd-5 build fix

--- src/egl/drivers/dri2/platform_drm.c.orig	2017-05-10 14:13:57.000000000 +0000
+++ src/egl/drivers/dri2/platform_drm.c
@@ -696,7 +696,9 @@ dri2_initialize_drm(_EGLDriver *drv, _EG
       }
       dri2_dpy->own_device = 1;
    } else {
+#ifdef F_DUPFD_CLOEXEC
       fd = fcntl(gbm_device_get_fd(gbm), F_DUPFD_CLOEXEC, 3);
+#endif
       if (fd < 0) {
          err = "DRI2: failed to fcntl() existing gbm device";
          goto cleanup;
