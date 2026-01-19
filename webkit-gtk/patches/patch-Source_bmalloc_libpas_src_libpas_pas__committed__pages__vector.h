$NetBSD$

--- Source/bmalloc/libpas/src/libpas/pas_committed_pages_vector.h.orig	2025-10-29 10:22:05.571630361 +0000
+++ Source/bmalloc/libpas/src/libpas/pas_committed_pages_vector.h
@@ -56,7 +56,7 @@ static inline bool pas_committed_pages_v
                                                            size_t page_index)
 {
     PAS_ASSERT(page_index < vector->size);
-#if PAS_OS(LINUX) || PAS_OS(WINDOWS)
+#if PAS_OS(LINUX) || PAS_OS(WINDOWS) || PAS_OS(NETBSD)
     return vector->raw_data[page_index];
 #else
     return vector->raw_data[page_index] & (MINCORE_REFERENCED |
