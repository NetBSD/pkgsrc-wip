$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chromecast/cast_core/runtime/browser/runtime_application_service_impl.cc.orig	2024-10-18 12:34:05.451124400 +0000
+++ chromecast/cast_core/runtime/browser/runtime_application_service_impl.cc
@@ -336,7 +336,7 @@ CastWebView::Scoped RuntimeApplicationSe
       GetFlagEntry(feature::kCastCoreIsRemoteControlMode,
                    config_.extra_features(), /*default_value=*/false);
   params->enabled_for_dev = IsEnabledForDev();
-#if BUILDFLAG(ENABLE_CAST_RECEIVER) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_CAST_RECEIVER) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   // cast_receiver::ApplicationControlsImpl constructs an instance of
   // url_rewrite::UrlRequestRewriteRulesManager. CastWebContentsImpl should NOT
   // construct its own instance, or UrlRequestRulesReceiver will crash when a
