$NetBSD$

--- base/allocator/allocator_shim_default_dispatch_to_glibc.cc.orig	2016-11-10 20:02:09.000000000 +0000
+++ base/allocator/allocator_shim_default_dispatch_to_glibc.cc
@@ -3,17 +3,46 @@
 // found in the LICENSE file.
 
 #include "base/allocator/allocator_shim.h"
+#include <stdio.h>
+#include <stdlib.h>
+#if defined(OS_FREEBSD)
+#include <malloc_np.h>
+#endif
 
 // This translation unit defines a default dispatch for the allocator shim which
 // routes allocations to libc functions.
-// The code here is strongly inspired from tcmalloc's libc_override_glibc.h.
+// The code here is strongly inspired from tcmalloc's override_glibc.h.
 
 extern "C" {
-void* __libc_malloc(size_t size);
-void* __libc_calloc(size_t n, size_t size);
-void* __libc_realloc(void* address, size_t size);
-void* __libc_memalign(size_t alignment, size_t size);
-void __libc_free(void* ptr);
+#if defined(OS_FREEBSD)
+void* __malloc(size_t size);
+void* __calloc(size_t n, size_t size);
+void* __realloc(void* address, size_t size);
+void* __memalign(size_t alignment, size_t size) {
+  void *ret;
+  if (__posix_memalign(&ret, alignment, size) != 0) {
+    return nullptr;
+  } else {
+    return ret;
+  }
+}
+int  __posix_memalign(void **ptr, size_t alignment, size_t size);
+void __free(void* ptr);
+#else
+#define __malloc malloc
+#define __calloc calloc
+#define __realloc realloc
+void* __memalign(size_t alignment, size_t size) {
+  void *ret;
+  if (posix_memalign(&ret, alignment, size) != 0) {
+    return nullptr;
+  } else {
+    return ret;
+  }
+}
+#define __posix_memalign posix_memalign
+#define __free free
+#endif
 }  // extern "C"
 
 namespace {
@@ -21,23 +50,27 @@ namespace {
 using base::allocator::AllocatorDispatch;
 
 void* GlibcMalloc(const AllocatorDispatch*, size_t size) {
-  return __libc_malloc(size);
+  return __malloc(size);
 }
 
 void* GlibcCalloc(const AllocatorDispatch*, size_t n, size_t size) {
-  return __libc_calloc(n, size);
+  return __calloc(n, size);
 }
 
 void* GlibcRealloc(const AllocatorDispatch*, void* address, size_t size) {
-  return __libc_realloc(address, size);
+  return __realloc(address, size);
 }
 
 void* GlibcMemalign(const AllocatorDispatch*, size_t alignment, size_t size) {
-  return __libc_memalign(alignment, size);
+  return __memalign(alignment, size);
 }
 
+/* int GlibcPosixMemalign(const AllocatorDispatch*, void** ptr, size_t alignment, size_t size) { */
+/*   return __posix_memalign(ptr, alignment, size); */
+/* } */
+
 void GlibcFree(const AllocatorDispatch*, void* address) {
-  __libc_free(address);
+  __free(address);
 }
 
 }  // namespace
