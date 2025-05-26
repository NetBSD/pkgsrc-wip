$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- printing/printing_context_system_dialog_win.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ printing/printing_context_system_dialog_win.cc
@@ -77,14 +77,28 @@ void PrintingContextSystemDialogWin::Ask
   PRINTPAGERANGE ranges[32];
   dialog_options.nStartPage = START_PAGE_GENERAL;
   if (max_pages) {
-    // Default initialize to print all the pages.
     memset(ranges, 0, sizeof(ranges));
-    ranges[0].nFromPage = 1;
-    ranges[0].nToPage = max_pages;
-    dialog_options.nPageRanges = 1;
-    dialog_options.nMaxPageRanges = std::size(ranges);
+
+    auto page_ranges = settings_->ranges();
+    if (!page_ranges.empty()) {
+      for (size_t i = 0; i < page_ranges.size(); i++) {
+        auto range = page_ranges[i];
+        ranges[i].nFromPage = range.from + 1;
+        ranges[i].nToPage = range.to + 1;
+      }
+      dialog_options.nPageRanges = page_ranges.size();
+
+      // Ensure the Pages radio button is selected.
+      dialog_options.Flags |= PD_PAGENUMS;
+    } else {
+      ranges[0].nFromPage = 1;
+      ranges[0].nToPage = max_pages;
+      dialog_options.nPageRanges = 1;
+    }
+
     dialog_options.nMinPage = 1;
     dialog_options.nMaxPage = max_pages;
+    dialog_options.nMaxPageRanges = std::size(ranges);
     dialog_options.lpPageRanges = ranges;
   } else {
     // No need to bother, we don't know how many pages are available.
