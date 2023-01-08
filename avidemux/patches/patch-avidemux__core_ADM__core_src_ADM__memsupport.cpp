$NetBSD$

memalign(3) is obsolete and not implemented on NetBSD. aligned_alloc(3) is the
same as memalign(3).

--- avidemux_core/ADM_core/src/ADM_memsupport.cpp.orig	2022-09-17 13:59:17.000000000 +0000
+++ avidemux_core/ADM_core/src/ADM_memsupport.cpp
@@ -110,7 +110,7 @@ void *ADM_aligned_alloc(size_t size)
 #ifdef _MSC_VER
 	return _aligned_malloc( size,16);
 #else
-    return memalign(16,size);
+    return aligned_alloc(16,size);
 #endif
 }
 void ADM_aligned_free(void *ptr)
