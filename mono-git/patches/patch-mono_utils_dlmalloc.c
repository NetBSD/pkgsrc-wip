$NetBSD$

--- mono/utils/dlmalloc.c.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/utils/dlmalloc.c
@@ -342,7 +342,7 @@ HAVE_MMAP                 default: 1 (tr
   able to unmap memory that may have be allocated using multiple calls
   to MMAP, so long as they are adjacent.
 
-HAVE_MREMAP               default: 1 on linux, else 0
+HAVE_MREMAP               default: 1 on linux and NetBSD, else 0
   If true realloc() uses mremap() to re-allocate large blocks and
   extend or shrink allocation spaces.
 
@@ -536,11 +536,11 @@ DEFAULT_MMAP_THRESHOLD       default: 25
 #define MMAP_CLEARS 1
 #endif  /* MMAP_CLEARS */
 #ifndef HAVE_MREMAP
-#ifdef linux
+#if defined(linux) || defined(__NetBSD__)
 #define HAVE_MREMAP 1
-#else   /* linux */
+#else   /* linux || __NetBSD__ */
 #define HAVE_MREMAP 0
-#endif  /* linux */
+#endif  /* linux || __NetBSD__ */
 #endif  /* HAVE_MREMAP */
 #ifndef MALLOC_FAILURE_ACTION
 #define MALLOC_FAILURE_ACTION  errno = ENOMEM;
@@ -1375,7 +1375,13 @@ static int win32munmap(void* ptr, size_t
 #endif /* HAVE_MMAP */
 
 #if HAVE_MMAP && HAVE_MREMAP
+#if defined(linux)
 #define CALL_MREMAP(addr, osz, nsz, mv) mremap((addr), (osz), (nsz), (mv))
+#elif defined(__NetBSD__)
+#define CALL_MREMAP(addr, osz, nsz, mv) mremap((addr), (osz), (addr), (nsz), (mv))
+#else
+#define CALL_MREMAP(addr, osz, nsz, mv) MFAIL
+#endif
 #else  /* HAVE_MMAP && HAVE_MREMAP */
 #define CALL_MREMAP(addr, osz, nsz, mv) MFAIL
 #endif /* HAVE_MMAP && HAVE_MREMAP */
