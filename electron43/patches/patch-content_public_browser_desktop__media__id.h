$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/desktop_media_id.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/browser/desktop_media_id.h
@@ -27,6 +27,8 @@ struct CONTENT_EXPORT DesktopMediaID {
   static constexpr Id kNullId = 0;
   // Represents a fake id to create a dummy capturer for autotests.
   static constexpr Id kFakeId = -3;
+  // Represents an id to use native macOS picker for screenshare
+  static constexpr Id kMacOsNativePickerId = -4;
 
 #if defined(USE_AURA) || BUILDFLAG(IS_MAC)
   // Assigns integer identifier to the |window| and returns its DesktopMediaID.
