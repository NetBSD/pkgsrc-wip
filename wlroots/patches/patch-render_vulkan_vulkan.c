$NetBSD$

* For makedev function

--- render/vulkan/vulkan.c.orig	2025-09-12 14:05:14.281653073 +0000
+++ render/vulkan/vulkan.c
@@ -1,4 +1,4 @@
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #undef _POSIX_C_SOURCE
 #endif
 #include <assert.h>
