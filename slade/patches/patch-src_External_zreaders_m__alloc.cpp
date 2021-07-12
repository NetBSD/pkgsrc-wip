$NetBSD$

Explicitly check for FreeBSD, Linux, macOS and Windows.
Use the generic algorithm for all other OS (formerly only for "__sun").

--- src/External/zreaders/m_alloc.cpp.orig	2020-05-27 23:08:34.000000000 +0000
+++ src/External/zreaders/m_alloc.cpp
@@ -57,14 +57,18 @@ namespace GC
 #endif
 #if defined(__APPLE__)
 #define _msize(p)				malloc_size(p)
-#elif defined(__sun)
-#define _msize(p)				(*((size_t*)(p)-1))
-#elif !defined(_WIN32)
+#elif defined(__FreeBSD__) || defined(__linux__)
 #define _msize(p)				malloc_usable_size(p)	// from glibc/FreeBSD
+#elif !defined(_WIN32)
+// For all other OS not handled above
+#define M_ALLOC_GENERIC  1
+#define _msize(p)				(*((size_t*)(p)-1))
 #endif
 
+
+
 #ifndef _DEBUG
-#if !defined(__sun)
+#if !M_ALLOC_GENERIC
 void *M_Malloc(size_t size)
 {
 	void *block = malloc(size);
@@ -134,7 +138,7 @@ void *M_Realloc(void *memblock, size_t s
 #include <crtdbg.h>
 #endif
 
-#if !defined(__sun)
+#if !M_ALLOC_GENERIC
 void *M_Malloc_Dbg(size_t size, const char *file, int lineno)
 {
 	void *block = _malloc_dbg(size, _NORMAL_BLOCK, file, lineno);
@@ -202,7 +206,7 @@ void *M_Realloc_Dbg(void *memblock, size
 #endif
 #endif
 
-#if !defined(__sun)
+#if !M_ALLOC_GENERIC
 void M_Free (void *block)
 {
 	if (block != NULL)
