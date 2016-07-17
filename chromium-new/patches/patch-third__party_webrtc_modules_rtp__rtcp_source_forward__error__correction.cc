$NetBSD$

--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2016-06-24 01:04:15.000000000 +0000
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -14,6 +14,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <iterator>
 
 #include "webrtc/base/checks.h"
