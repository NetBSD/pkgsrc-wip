$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- skia/ext/skcolorspace_trfn.cc.orig	2024-10-18 12:34:32.221660000 +0000
+++ skia/ext/skcolorspace_trfn.cc
@@ -7,6 +7,8 @@
 #pragma allow_unsafe_buffers
 #endif
 
+#include <cmath>
+
 #include "skia/ext/skcolorspace_trfn.h"
 
 #include <cmath>
