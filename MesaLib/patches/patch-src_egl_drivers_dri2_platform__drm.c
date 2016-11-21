$NetBSD$

netbsd-5 build fix

--- src/egl/drivers/dri2/platform_drm.c.orig	2016-11-10 22:06:40.000000000 +0000
+++ src/egl/drivers/dri2/platform_drm.c
@@ -683,7 +683,9 @@ dri2_initialize_drm(_EGLDriver *drv, _EG
          goto cleanup;
       }
    } else {
+#ifdef F_DUPFD_CLOEXEC
       fd = fcntl(gbm_device_get_fd(gbm), F_DUPFD_CLOEXEC, 3);
+#endif
       if (fd < 0) {
          err = "DRI2: failed to fcntl() existing gbm device";
          goto cleanup;
