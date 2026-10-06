$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/clipboard/scoped_clipboard_writer.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/base/clipboard/scoped_clipboard_writer.h
@@ -88,6 +88,10 @@ class COMPONENT_EXPORT(UI_BASE_CLIPBOARD
   // This is only used to write custom format data.
   void WriteData(const std::u16string& format, mojo_base::BigBuffer data);
 
+  // write raw (non-pickled) data to the clipboard
+  void WriteUnsafeRawData(const std::u16string& format,
+                          mojo_base::BigBuffer data);
+
   void WriteImage(const SkBitmap& bitmap);
 
   // Mark the data to be written as confidential.
