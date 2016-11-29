$NetBSD$

--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2016-11-10 20:03:06.000000000 +0000
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -13,6 +13,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <iterator>
 #include <utility>
 
