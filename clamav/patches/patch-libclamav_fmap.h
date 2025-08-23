$NetBSD: patch-libclamav_fmap.h,v 1.3 2021/11/08 14:49:23 taca Exp $

rename gets to my_gets to avoid conflict with fortify/ssp - they use
macros to override libc functions

--- libclamav/fmap.h.orig	2025-06-17 03:41:15.000000000 +0200
+++ libclamav/fmap.h	2025-08-23 16:37:55.759812359 +0200
@@ -80,7 +80,7 @@
     void (*unmap)(fmap_t *);
     const void *(*need)(fmap_t *, size_t at, size_t len, int lock);
     const void *(*need_offstr)(fmap_t *, size_t at, size_t len_hint);
-    const void *(*gets)(fmap_t *, char *dst, size_t *at, size_t max_len);
+    const void *(*my_gets)(fmap_t *, char *dst, size_t *at, size_t max_len);
     void (*unneed_off)(fmap_t *, size_t at, size_t len);
     void *windows_file_handle;
     void *windows_map_handle;
@@ -357,7 +357,7 @@
  */
 static inline const void *fmap_gets(fmap_t *m, char *dst, size_t *at, size_t max_len)
 {
-    return m->gets(m, dst, at, max_len);
+    return m->my_gets(m, dst, at, max_len);
 }
 
 /**
