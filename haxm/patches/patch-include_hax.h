$NetBSD$

--- include/hax.h.orig	2018-11-21 06:34:18.000000000 +0000
+++ include/hax.h
@@ -119,9 +119,9 @@ void hax_vfree_aligned(void *va, uint32_
                        uint32_t alignment);
 
 struct hax_vcpu_mem {
-    uint32_t size;
-    uint64_t uva;
-    void *kva;
+    vsize_t size;
+    vaddr_t uva;
+    vaddr_t kva;
     void *hinfo;
 };
 
@@ -269,6 +269,9 @@ int hax_em64t_enabled(void);
 #ifdef HAX_PLATFORM_LINUX
 #include "linux/hax_linux.h"
 #endif
+#ifdef HAX_PLATFORM_NETBSD
+#include "netbsd/hax_netbsd.h"
+#endif
 #ifdef HAX_PLATFORM_WINDOWS
 #include "windows/hax_windows.h"
 #endif
