$NetBSD$

Apply fix from https://github.com/llvm/llvm-project/pull/207569

in an attempt at fixing what's similar to

https://github.com/llvm/llvm-project/issues/199778

--- libcxx/include/__locale_dir/locale_base_api.h.orig	2026-11-20 23:43:47.411361796 +0000
+++ libcxx/include/__locale_dir/locale_base_api.h
@@ -134,7 +134,9 @@
 //       (by providing global non-reserved names) and the new API. As we move individual platforms
 //       towards the new way of defining the locale base API, this should disappear since each platform
 //       will define those directly.
+#ifdef __MVS__
 #    include <__locale_dir/locale_base_api/ibm.h>
+#endif
 
 #    include <__locale_dir/locale_base_api/bsd_locale_fallbacks.h>
 
