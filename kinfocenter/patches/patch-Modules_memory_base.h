$NetBSD$

resotore NetBSD/OpenBSD values lost sometime after 5.16.4

--- Modules/memory/base.h.orig	2020-05-05 14:39:33.000000000 +0000
+++ Modules/memory/base.h
@@ -25,6 +25,9 @@ enum { /* entries for memoryInfos[] */
 #if !defined(__NetBSD__) && !defined(__OpenBSD__)
 	SHARED_MEM, /* shared memory size */
     BUFFER_MEM, /* buffered memory size */
+#else
+	ACTIVE_MEM,
+	INACTIVE_MEM,
 #endif
 	CACHED_MEM, /* cache memory size (located in ram) */
 	SWAP_MEM, /* total size of all swap-partitions */
