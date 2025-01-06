$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- printing/printing_context_mac.mm.orig	2024-10-18 12:34:31.741884500 +0000
+++ printing/printing_context_mac.mm
@@ -527,7 +527,8 @@ mojom::ResultCode PrintingContextMac::Up
         !SetCollateInPrintSettings(settings_->collate()) ||
         !SetDuplexModeInPrintSettings(settings_->duplex_mode()) ||
         !SetOutputColor(static_cast<int>(settings_->color())) ||
-        !SetResolution(settings_->dpi_size())) {
+        !SetResolution(settings_->dpi_size()) ||
+        !SetPrintRangeInPrintSettings(settings_->ranges()) ) {
       return OnError();
     }
   }
@@ -680,6 +681,22 @@ bool PrintingContextMac::SetCopiesInPrin
   return PMSetCopies(print_settings, copies, false) == noErr;
 }
 
+bool PrintingContextMac::SetPrintRangeInPrintSettings(const PageRanges& ranges) {
+  // Default is already NSPrintAllPages - we can safely bail.
+  if (ranges.empty())
+    return true;
+
+  PMPrintSettings print_settings =
+      static_cast<PMPrintSettings>([print_info_ PMPrintSettings]);
+
+  // macOS does not allow multiple ranges, so pluck the first.
+  auto range = ranges.front();
+  bool set_first_page = PMSetFirstPage(print_settings, range.from + 1, false) == noErr;
+  bool set_last_page = PMSetLastPage(print_settings, range.to + 1, false) == noErr;
+
+  return set_first_page && set_last_page;
+}
+
 bool PrintingContextMac::SetCollateInPrintSettings(bool collate) {
   PMPrintSettings print_settings =
       static_cast<PMPrintSettings>([print_info_ PMPrintSettings]);
