$NetBSD$

--- base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2020-06-25 09:31:18.000000000 +0000
+++ base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -24,7 +24,7 @@
 #if defined(OS_ANDROID)
 #include <sys/prctl.h>
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/resource.h>
 
 #include <algorithm>
