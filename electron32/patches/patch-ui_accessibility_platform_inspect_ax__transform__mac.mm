$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/accessibility/platform/inspect/ax_transform_mac.mm.orig	2024-10-18 12:35:12.260455400 +0000
+++ ui/accessibility/platform/inspect/ax_transform_mac.mm
@@ -108,6 +108,7 @@ base::Value AXNSObjectToBaseValue(id val
     }
   }
 
+#if !IS_MAS_BUILD()
   // AXTextMarker
   if (IsAXTextMarker(value)) {
     return AXTextMarkerToBaseValue(value, indexer);
@@ -117,6 +118,7 @@ base::Value AXNSObjectToBaseValue(id val
   if (IsAXTextMarkerRange(value)) {
     return AXTextMarkerRangeToBaseValue(value, indexer);
   }
+#endif
 
   // Accessible object
   if (AXElementWrapper::IsValidElement(value)) {
