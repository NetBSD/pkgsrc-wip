$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors.inc.orig	2017-12-21 18:53:10.000000000 +0000
+++ lib/sanitizer_common/sanitizer_common_interceptors.inc
@@ -1703,6 +1703,7 @@ FORMAT_INTERCEPTOR_IMPL(__isoc99_snprint
 
 #if SANITIZER_INTERCEPT_IOCTL
 #include "sanitizer_common_interceptors_ioctl.inc"
+#include "sanitizer_netbsd_interceptors_ioctl.inc"
 INTERCEPTOR(int, ioctl, int d, unsigned long request, ...) {
   // We need a frame pointer, because we call into ioctl_common_[pre|post] which
   // can trigger a report and we need to be able to unwind through this
