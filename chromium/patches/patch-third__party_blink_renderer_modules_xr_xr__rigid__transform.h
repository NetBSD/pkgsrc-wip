$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/xr/xr_rigid_transform.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ third_party/blink/renderer/modules/xr/xr_rigid_transform.h
@@ -12,9 +12,7 @@
 #include "third_party/blink/renderer/modules/modules_export.h"
 #include "third_party/blink/renderer/platform/bindings/script_wrappable.h"
 
-namespace gfx {
-class Transform;
-}
+#include "ui/gfx/geometry/transform.h"
 
 namespace blink {
 
