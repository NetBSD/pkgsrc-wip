$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors_ioctl.inc.orig	2017-12-21 18:53:10.000000000 +0000
+++ lib/sanitizer_common/sanitizer_common_interceptors_ioctl.inc
@@ -10,6 +10,8 @@
 // Ioctl handling in common sanitizer interceptors.
 //===----------------------------------------------------------------------===//
 
+#if !SANITIZER_NETBSD
+
 #include "sanitizer_flags.h"
 
 struct ioctl_desc {
@@ -604,3 +606,5 @@ static void ioctl_common_post(void *ctx,
     COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ifc->ifc_ifcu.ifcu_req, ifc->ifc_len);
   }
 }
+
+#endif
