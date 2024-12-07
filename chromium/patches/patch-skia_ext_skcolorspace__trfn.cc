$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- skia/ext/skcolorspace_trfn.cc.orig	2024-12-03 23:30:25.665275300 +0000
+++ skia/ext/skcolorspace_trfn.cc
@@ -7,6 +7,8 @@
 #pragma allow_unsafe_buffers
 #endif
 
+#include <cmath>
+
 #include "skia/ext/skcolorspace_trfn.h"
 
 #include <cmath>
