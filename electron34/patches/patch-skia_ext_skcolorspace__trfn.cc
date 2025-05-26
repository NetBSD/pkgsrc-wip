$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- skia/ext/skcolorspace_trfn.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ skia/ext/skcolorspace_trfn.cc
@@ -7,6 +7,8 @@
 #pragma allow_unsafe_buffers
 #endif
 
+#include <cmath>
+
 #include "skia/ext/skcolorspace_trfn.h"
 
 #include <cmath>
