$NetBSD: patch-src_glsl_ralloc.c,v 1.4 2016/02/23 11:16:55 jperkin Exp $

FreeBSD reported atexit bug for 10.6:
https://bugs.freedesktop.org/show_bug.cgi?id=91869

* Fix exit time segfault of qt5 application with modular xorg
* Provide compat strnlen for older Darwin.

--- src/util/ralloc.c.orig	2017-02-13 11:55:50.000000000 +0000
+++ src/util/ralloc.c
@@ -325,7 +325,7 @@ ralloc_parent(const void *ptr)
 
 static void *autofree_context = NULL;
 
-static void
+static void __attribute__((__destructor__))
 autofree(void)
 {
    ralloc_free(autofree_context);
@@ -336,7 +336,6 @@ ralloc_autofree_context(void)
 {
    if (unlikely(autofree_context == NULL)) {
       autofree_context = ralloc_context(NULL);
-      atexit(autofree);
    }
    return autofree_context;
 }
@@ -373,7 +372,14 @@ ralloc_strndup(const void *ctx, const ch
    if (unlikely(str == NULL))
       return NULL;
 
+#if (defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__-0 < 1070)
+   for (n = 0; n < max; n++, str++) {
+     if (!*str)
+       break;
+   }
+#else
    n = strnlen(str, max);
+#endif
    ptr = ralloc_array(ctx, char, n + 1);
    memcpy(ptr, str, n);
    ptr[n] = '\0';
