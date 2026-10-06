$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/clipboard/scoped_clipboard_writer.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/base/clipboard/scoped_clipboard_writer.cc
@@ -227,6 +227,16 @@ void ScopedClipboardWriter::WriteData(co
   }
 }
 
+void ScopedClipboardWriter::WriteUnsafeRawData(const std::u16string& format,
+                                               mojo_base::BigBuffer data) {
+  static constexpr int kMaxRegisteredFormats = 100;
+  if (counter_ >= kMaxRegisteredFormats)
+    return;
+  counter_++;
+  platform_representations_.push_back(
+      {base::UTF16ToUTF8(format), std::move(data)});
+}
+
 void ScopedClipboardWriter::Reset() {
   objects_.clear();
   platform_representations_.clear();
