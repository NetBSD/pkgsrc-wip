$NetBSD$

--- lib/intel_os.c.orig	2015-08-17 16:40:03.000000000 +0000
+++ lib/intel_os.c
@@ -112,6 +112,13 @@ intel_get_avail_ram_mb(void)
 
 	retval = sysinf.freeram;
 	retval *= sysinf.mem_unit;
+#elif defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES) /* NetBSD */
+	long pagesize, npages;
+
+	pagesize = sysconf(_SC_PAGESIZE);
+        npages = sysconf(_SC_PHYS_PAGES);
+
+	retval = (uint64_t) pagesize * npages;
 #elif defined(_SC_PAGESIZE) && defined(_SC_AVPHYS_PAGES) /* Solaris */
 	long pagesize, npages;
 
@@ -146,6 +153,9 @@ intel_get_total_swap_mb(void)
 
 	retval = sysinf.freeswap;
 	retval *= sysinf.mem_unit;
+#elif defined(__NetBSD__)
+#warning fixme
+	return 0;
 #elif defined(HAVE_SWAPCTL) /* Solaris */
 	long pagesize = sysconf(_SC_PAGESIZE);
 	uint64_t totalpages = 0;
