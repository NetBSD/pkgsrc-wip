$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- printing/printing_context_mac.h.orig	2024-10-18 12:34:31.741884500 +0000
+++ printing/printing_context_mac.h
@@ -84,6 +84,10 @@ class COMPONENT_EXPORT(PRINTING) Printin
   // Returns true if the orientation was set.
   bool SetOrientationIsLandscape(bool landscape);
 
+  // Set the page range in native print info object.
+  // Returns true if the range was set.
+  bool SetPrintRangeInPrintSettings(const PageRanges& ranges);
+
   // Sets duplex mode in PMPrintSettings.
   // Returns true if duplex mode is set.
   bool SetDuplexModeInPrintSettings(mojom::DuplexMode mode);
