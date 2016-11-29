$NetBSD$

--- third_party/webrtc/modules/remote_bitrate_estimator/overuse_detector.cc.orig	2016-11-10 20:03:06.000000000 +0000
+++ third_party/webrtc/modules/remote_bitrate_estimator/overuse_detector.cc
@@ -14,6 +14,7 @@
 #include <stdlib.h>
 
 #include <algorithm>
+#include <cstdio>
 #include <sstream>
 #include <string>
 
