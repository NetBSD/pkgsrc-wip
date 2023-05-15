$NetBSD$

GCC 13 fixes.

--- dom/media/webrtc/sdp/RsdparsaSdpGlue.cpp.orig	2023-05-12 14:15:02.145219021 +0200
+++ dom/media/webrtc/sdp/RsdparsaSdpGlue.cpp	2023-05-12 14:15:48.433146715 +0200
@@ -3,6 +3,7 @@
 /* This Source Code Form is subject to the terms of the Mozilla Public
  * License, v. 2.0. If a copy of the MPL was not distributed with this file,
  * You can obtain one at http://mozilla.org/MPL/2.0/. */
+#include <cstdint>
 #include <string>
 
 #include "sdp/RsdparsaSdpInc.h"
