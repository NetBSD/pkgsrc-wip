$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/common/features.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/common/features.cc
@@ -2754,6 +2754,12 @@ BASE_FEATURE(kWebAppManifestLockScreen,
              "WebAppManifestLockScreen",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
+// Allow denormals in AudioWorklet and ScriptProcessorNode, to enable strict
+// JavaScript denormal compliance.  See https://crbug.com/382005099.
+BASE_FEATURE(kWebAudioAllowDenormalInProcessing,
+             "WebAudioAllowDenormalInProcessing",
+             base::FEATURE_DISABLED_BY_DEFAULT);
+
 // Parameters can be used to control to which latency hints the feature is
 // applied.
 BASE_FEATURE_PARAM(bool,
