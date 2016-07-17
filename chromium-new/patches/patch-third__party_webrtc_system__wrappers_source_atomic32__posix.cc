$NetBSD$

--- third_party/webrtc/system_wrappers/source/atomic32_posix.cc.orig	2016-06-24 01:04:15.000000000 +0000
+++ third_party/webrtc/system_wrappers/source/atomic32_posix.cc
@@ -12,7 +12,11 @@
 
 #include <assert.h>
 #include <inttypes.h>
+#if defined(WEBRTC_BSD)
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 #include "webrtc/common_types.h"
 
