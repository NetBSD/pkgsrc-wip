$NetBSD$

Option from OpenBSD Xenocara

Disable the code that allocates W|X memory.  There is fallback code that
gets used if allocating W|X memory fails, which is probably a bit slower.
However, that is much better than commit a W^X violation which currently
gets you killed.

--- src/gallium/auxiliary/rtasm/rtasm_execmem.c.orig	2019-03-15 01:02:19.000000000 +0000
+++ src/gallium/auxiliary/rtasm/rtasm_execmem.c
@@ -68,6 +68,15 @@ static mtx_t exec_mutex = _MTX_INITIALIZ
 static struct mem_block *exec_heap = NULL;
 static unsigned char *exec_mem = NULL;
 
+#if defined(DISABLE_WX_MEMORY)
+
+static int
+init_heap(void)
+{
+   return 0;
+}
+
+#else /* !DISABLE_WX_MEMORY */
 
 static int
 init_heap(void)
@@ -83,6 +92,7 @@ init_heap(void)
    return (exec_mem != MAP_FAILED);
 }
 
+#endif /* DISABLE_WX_MEMORY */
 
 void *
 rtasm_exec_malloc(size_t size)
