$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/clipboard/scoped_clipboard_writer.cc.orig	2024-10-18 12:35:12.348420100 +0000
+++ ui/base/clipboard/scoped_clipboard_writer.cc
@@ -229,6 +229,16 @@ void ScopedClipboardWriter::WriteEncoded
 }
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
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
