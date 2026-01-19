$NetBSD$

--- Source/bmalloc/libpas/src/libpas/pas_page_malloc.c.orig	2025-10-29 10:28:33.883505020 +0000
+++ Source/bmalloc/libpas/src/libpas/pas_page_malloc.c
@@ -323,7 +323,7 @@ static void commit_impl(void* ptr, size_
     }
 #elif PAS_PLATFORM(PLAYSTATION)
     // We don't need to call madvise to map page.
-#elif PAS_OS(FREEBSD)
+#elif PAS_OS(FREEBSD) || PAS_OS(NETBSD)
     PAS_SYSCALL(madvise(ptr, size, MADV_NORMAL));
 #endif
 }
@@ -366,7 +366,7 @@ static void decommit_impl(void* ptr, siz
         pas_page_malloc_zero_fill(ptr, size);
     else
         PAS_SYSCALL(madvise(ptr, size, MADV_FREE_REUSABLE));
-#elif PAS_OS(FREEBSD)
+#elif PAS_OS(FREEBSD) || PAS_OS(NETBSD)
     PAS_SYSCALL(madvise(ptr, size, MADV_FREE));
 #elif PAS_OS(LINUX)
     PAS_SYSCALL(madvise(ptr, size, MADV_DONTNEED));
