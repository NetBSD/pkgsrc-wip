$NetBSD$

Guard GNU libc-ism (use of mallinfo()).

--- lib/mm/memlock.c.orig	2021-05-07 21:14:09.000000000 +0000
+++ lib/mm/memlock.c
@@ -22,6 +22,7 @@
 #include <limits.h>
 #include <fcntl.h>
 #include <unistd.h>
+#include <features.h>	/* for __GNU_LIBRARY__ check */
 #include <sys/mman.h>
 #include <sys/time.h>
 #include <sys/resource.h>
@@ -176,6 +177,7 @@ static void _allocate_memory(void)
 	}
 	/* FIXME else warn user setting got ignored */
 
+#ifdef __GNU_LIBRARY__	/* mallinfo() is glibc-specific */
         /*
          *  When a brk() fails due to fragmented address space (which sometimes
          *  happens when we try to grab 8M or so), glibc will make a new
@@ -213,6 +215,7 @@ static void _allocate_memory(void)
 			break;
 		}
 	}
+#endif /* __GNU_LIBRARY__ */
 
 	if ((_malloc_mem = malloc(_size_malloc)))
 		_touch_memory(_malloc_mem, _size_malloc);
