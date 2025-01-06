$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/clipboard/scoped_clipboard_writer.h.orig	2024-10-18 12:35:12.348420100 +0000
+++ ui/base/clipboard/scoped_clipboard_writer.h
@@ -89,6 +89,10 @@ class COMPONENT_EXPORT(UI_BASE_CLIPBOARD
   // This is only used to write custom format data.
   void WriteData(const std::u16string& format, mojo_base::BigBuffer data);
 
+  // write raw (non-pickled) data to the clipboard
+  void WriteUnsafeRawData(const std::u16string& format,
+                          mojo_base::BigBuffer data);
+
   void WriteImage(const SkBitmap& bitmap);
 
 #if BUILDFLAG(IS_CHROMEOS_LACROS)
