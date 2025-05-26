$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/platform/web_content_settings_client.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/public/platform/web_content_settings_client.h
@@ -55,6 +55,9 @@ class WebContentSettingsClient {
   // Controls whether access to write the clipboard is allowed for this frame.
   virtual bool AllowWriteToClipboard() { return false; }
 
+  // Controls whether synchronous access to read the clipboard is allowed for this frame.
+  virtual bool AllowReadFromClipboardSync() { return false; }
+
   // Controls whether to enable MutationEvents for this frame.
   // The common use case of this method is actually to selectively disable
   // MutationEvents, but it's been named for consistency with the rest of the
