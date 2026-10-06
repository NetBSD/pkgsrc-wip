$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gtk/printing/print_dialog_gtk.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/gtk/printing/print_dialog_gtk.cc
@@ -247,6 +247,24 @@ void PrintDialogGtk::UpdateSettings(
 
   gtk_print_settings_set_n_copies(gtk_settings_, settings->copies());
   gtk_print_settings_set_collate(gtk_settings_, settings->collate());
+
+  auto print_ranges = settings->ranges();
+  if (!print_ranges.empty()) {
+    // Tell the system that we only intend to print a subset of pages.
+    gtk_print_settings_set_print_pages(gtk_settings_, GTK_PRINT_PAGES_RANGES);
+
+    GtkPageRange* ranges;
+    ranges = g_new(GtkPageRange, print_ranges.size());
+    for (size_t i = 0; i < print_ranges.size(); i++) {
+      auto range = print_ranges[i];
+      ranges[i].start = range.from;
+      ranges[i].end = range.to;
+    }
+
+    gtk_print_settings_set_page_ranges(gtk_settings_, ranges, 1);
+    g_free(ranges);
+  }
+
   if (settings->dpi_horizontal() > 0 && settings->dpi_vertical() > 0) {
     gtk_print_settings_set_resolution_xy(
         gtk_settings_, settings->dpi_horizontal(), settings->dpi_vertical());
@@ -438,7 +456,7 @@ void PrintDialogGtk::ShowDialog(
   GtkPrintCapabilities cap = static_cast<GtkPrintCapabilities>(
       GTK_PRINT_CAPABILITY_GENERATE_PDF | GTK_PRINT_CAPABILITY_PAGE_SET |
       GTK_PRINT_CAPABILITY_COPIES | GTK_PRINT_CAPABILITY_COLLATE |
-      GTK_PRINT_CAPABILITY_REVERSE);
+      GTK_PRINT_CAPABILITY_REVERSE | GTK_PRINT_CAPABILITY_GENERATE_PS);
   gtk_print_unix_dialog_set_manual_capabilities(
       GTK_PRINT_UNIX_DIALOG(dialog_.get()), cap);
   gtk_print_unix_dialog_set_embed_page_setup(
