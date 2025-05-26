$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/accessibility/platform/inspect/ax_transform_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/accessibility/platform/inspect/ax_transform_mac.mm
@@ -11,6 +11,7 @@
 
 #include "base/apple/foundation_util.h"
 #include "base/strings/sys_string_conversions.h"
+#include "electron/mas.h"
 #include "ui/accessibility/ax_range.h"
 #include "ui/accessibility/platform/ax_platform_node.h"
 #include "ui/accessibility/platform/ax_platform_node_cocoa.h"
@@ -111,6 +112,7 @@ base::Value AXNSObjectToBaseValue(id val
     }
   }
 
+#if !IS_MAS_BUILD()
   // AXTextMarker
   if (IsAXTextMarker(value)) {
     return AXTextMarkerToBaseValue(value, indexer);
@@ -120,6 +122,7 @@ base::Value AXNSObjectToBaseValue(id val
   if (IsAXTextMarkerRange(value)) {
     return AXTextMarkerRangeToBaseValue(value, indexer);
   }
+#endif
 
   // Accessible object
   if (AXElementWrapper::IsValidElement(value)) {
