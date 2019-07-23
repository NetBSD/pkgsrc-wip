$NetBSD: patch-include_drm_drm.h,v 1.4 2016/04/29 11:17:34 wiz Exp $

NetBSD xsrc:
protect from redefinition

Fix compilation on systems that don't provide O_CLOEXEC.

--- include/drm/drm.h.orig	2019-07-02 18:36:50.000000000 +0000
+++ include/drm/drm.h
@@ -47,6 +47,10 @@ typedef unsigned int drm_handle_t;
 #include <stdint.h>
 #include <sys/ioccom.h>
 #include <sys/types.h>
+#if !defined(__NetBSD__) || !defined(__linux_sized_types__)
+#if defined(__NetBSD__) && !defined(__linux_sized_types__)
+#define __linux_sized_types__
+#endif /* __NetBSD__ */
 typedef int8_t   __s8;
 typedef uint8_t  __u8;
 typedef int16_t  __s16;
@@ -55,6 +59,7 @@ typedef int32_t  __s32;
 typedef uint32_t __u32;
 typedef int64_t  __s64;
 typedef uint64_t __u64;
+#endif /* __linux_sized_types__ */
 typedef size_t   __kernel_size_t;
 typedef unsigned long drm_handle_t;
 
@@ -699,7 +704,11 @@ struct drm_set_client_cap {
 };
 
 #define DRM_RDWR O_RDWR
+#ifdef O_CLOEXEC
 #define DRM_CLOEXEC O_CLOEXEC
+#else
+#define DRM_CLOEXEC 0
+#endif
 struct drm_prime_handle {
 	__u32 handle;
 
