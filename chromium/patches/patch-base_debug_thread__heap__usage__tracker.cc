$NetBSD$

--- base/debug/thread_heap_usage_tracker.cc.orig	2017-02-02 02:02:47.000000000 +0000
+++ base/debug/thread_heap_usage_tracker.cc
@@ -14,11 +14,13 @@
 #include "base/threading/thread_local_storage.h"
 #include "build/build_config.h"
 
+#if !defined(OS_BSD)
 #if defined(OS_MACOSX) || defined(OS_IOS)
 #include <malloc/malloc.h>
 #else
 #include <malloc.h>
 #endif
+#endif
 
 namespace base {
 namespace debug {
