$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/common/features.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/public/common/features.h
@@ -1791,6 +1791,7 @@ BLINK_COMMON_EXPORT BASE_DECLARE_FEATURE
 BLINK_COMMON_EXPORT BASE_DECLARE_FEATURE(kWebAppEnableUrlHandlers);
 BLINK_COMMON_EXPORT BASE_DECLARE_FEATURE(kWebAppManifestLockScreen);
 
+BLINK_COMMON_EXPORT BASE_DECLARE_FEATURE(kWebAudioAllowDenormalInProcessing);
 // Parameters are used to control to which latency hints the feature is applied
 BLINK_COMMON_EXPORT BASE_DECLARE_FEATURE_PARAM(
     bool,
