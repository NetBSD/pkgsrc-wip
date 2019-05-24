$NetBSD: patch-include_GL_internal_dri__interface.h,v 1.1 2018/10/07 23:49:31 ryoon Exp $

From FreeBSD ports graphics/mesa-dri 17.2.4.

GCC on 9.x doesn't allow types to be overwritten, these types are defined
in drm.h also, which causes build issues in xorg-server.

From NetBSD xsrc: prevent re-definitions from drm.h

--- include/GL/internal/dri_interface.h.orig	2019-04-17 22:16:19.000000000 +0000
+++ include/GL/internal/dri_interface.h
@@ -40,13 +40,19 @@
 #ifndef DRI_INTERFACE_H
 #define DRI_INTERFACE_H
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#include <drm.h>
+#else
 #ifdef HAVE_LIBDRM
 #include <drm.h>
 #else
+#if !defined(_DRM_H_) || !defined(STRICT_XSRC_NETBSD)
 typedef unsigned int drm_context_t;
 typedef unsigned int drm_drawable_t;
 typedef struct drm_clip_rect drm_clip_rect_t;
 #endif
+#endif
+#endif /* __FreeBSD__ || __DragonFly__ */
 
 #include <GL/gl.h>
 
