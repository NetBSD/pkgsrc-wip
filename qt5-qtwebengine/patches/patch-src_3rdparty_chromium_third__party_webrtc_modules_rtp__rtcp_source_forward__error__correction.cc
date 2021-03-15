$NetBSD$

--- src/3rdparty/chromium/third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2020-07-15 19:01:41.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -13,6 +13,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <utility>
 
 #include "absl/algorithm/container.h"
