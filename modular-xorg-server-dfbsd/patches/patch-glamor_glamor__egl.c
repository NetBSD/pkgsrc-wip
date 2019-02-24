$NetBSD$

Option to revert

2017-05-18	glamor_egl: Avoid flink names in glamor_egl_create_textured_pixmap().
commit	59de50d6ef3331ee03eb82d4acba45aa75c70d42

glamor_egl: Avoid flink names in glamor_egl_create_textured_pixmap().
Using flink is banned on render nodes, and they needlessly expose our
screen pixmap contents to any authenticated client.  This also
incidentally drops the dependency on EGL_MESA_drm_image.

--- glamor/glamor_egl.c.orig	2018-10-15 15:59:33.000000000 +0000
+++ glamor/glamor_egl.c
@@ -93,6 +93,40 @@ glamor_egl_make_current(struct glamor_co
     }
 }
 
+#if defined(REVERT_FLINK)
+static EGLImageKHR
+_glamor_egl_create_image(struct glamor_egl_screen_private *glamor_egl,
+                         int width, int height, int stride, int name, int depth)
+{
+    EGLImageKHR image;
+
+    EGLint attribs[] = {
+        EGL_WIDTH, 0,
+        EGL_HEIGHT, 0,
+        EGL_DRM_BUFFER_STRIDE_MESA, 0,
+        EGL_DRM_BUFFER_FORMAT_MESA,
+        EGL_DRM_BUFFER_FORMAT_ARGB32_MESA,
+        EGL_DRM_BUFFER_USE_MESA,
+        EGL_DRM_BUFFER_USE_SHARE_MESA | EGL_DRM_BUFFER_USE_SCANOUT_MESA,
+        EGL_NONE
+    };
+    attribs[1] = width;
+    attribs[3] = height;
+    attribs[5] = stride;
+    if (depth != 32 && depth != 24)
+        return EGL_NO_IMAGE_KHR;
+    image = eglCreateImageKHR(glamor_egl->display,
+                              glamor_egl->context,
+                              EGL_DRM_BUFFER_MESA,
+                              (void *) (uintptr_t) name,
+                              attribs);
+    if (image == EGL_NO_IMAGE_KHR)
+        return EGL_NO_IMAGE_KHR;
+
+    return image;
+}
+#endif
+
 static int
 glamor_get_flink_name(int fd, int handle, int *name)
 {
@@ -184,6 +218,48 @@ glamor_egl_create_textured_pixmap(Pixmap
 {
     ScreenPtr screen = pixmap->drawable.pScreen;
     ScrnInfoPtr scrn = xf86ScreenToScrn(screen);
+
+#if defined(REVERT_FLINK)
+    struct glamor_screen_private *glamor_priv =
+        glamor_get_screen_private(screen);
+    struct glamor_egl_screen_private *glamor_egl;
+    EGLImageKHR image;
+    GLuint texture;
+    int name;
+    Bool ret = FALSE;
+
+    glamor_egl = glamor_egl_get_screen_private(scrn);
+
+    glamor_make_current(glamor_priv);
+    if (!glamor_get_flink_name(glamor_egl->fd, handle, &name)) {
+        xf86DrvMsg(scrn->scrnIndex, X_ERROR,
+                   "Couldn't flink pixmap handle\n");
+        glamor_set_pixmap_type(pixmap, GLAMOR_DRM_ONLY);
+        assert(0);
+        return FALSE;
+    }
+
+    image = _glamor_egl_create_image(glamor_egl,
+                                     pixmap->drawable.width,
+                                     pixmap->drawable.height,
+                                     ((stride * 8 +
+                                       7) / pixmap->drawable.bitsPerPixel),
+                                     name, pixmap->drawable.depth);
+    if (image == EGL_NO_IMAGE_KHR) {
+        glamor_set_pixmap_type(pixmap, GLAMOR_DRM_ONLY);
+        goto done;
+    }
+    glamor_create_texture_from_image(screen, image, &texture);
+    glamor_set_pixmap_type(pixmap, GLAMOR_TEXTURE_DRM);
+    glamor_set_pixmap_texture(pixmap, texture);
+    glamor_egl_set_pixmap_image(pixmap, image, FALSE);
+    ret = TRUE;
+ 
+ done:
+    return ret;
+}
+
+#else /* !REVERT_FLINK */
     struct glamor_egl_screen_private *glamor_egl =
         glamor_egl_get_screen_private(scrn);
     int ret, fd;
@@ -213,6 +289,7 @@ glamor_egl_create_textured_pixmap(Pixmap
     close(fd);
     return TRUE;
 }
+#endif /* REVERT_FLINK */
 
 Bool
 glamor_egl_create_textured_pixmap_from_gbm_bo(PixmapPtr pixmap,
@@ -934,6 +1011,9 @@ glamor_egl_init(ScrnInfoPtr scrn, int fd
 		goto error;  \
 	}
 
+#if defined(REVERT_FLINK)
+    GLAMOR_CHECK_EGL_EXTENSION(MESA_drm_image);
+#endif
     GLAMOR_CHECK_EGL_EXTENSION(KHR_surfaceless_context);
 
     if (eglBindAPI(EGL_OPENGL_API)) {
