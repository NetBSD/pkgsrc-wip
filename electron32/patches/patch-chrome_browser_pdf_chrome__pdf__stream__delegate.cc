$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/pdf/chrome_pdf_stream_delegate.cc.orig	2024-10-18 12:34:01.821122000 +0000
+++ chrome/browser/pdf/chrome_pdf_stream_delegate.cc
@@ -45,6 +45,7 @@ namespace {
 // hierarchy is: enterprise policy > user choice > finch experiment.
 bool ShouldEnableSkiaRenderer(content::WebContents* contents) {
   CHECK(contents);
+#if 0
   const PrefService* prefs =
       Profile::FromBrowserContext(contents->GetBrowserContext())->GetPrefs();
 
@@ -52,6 +53,7 @@ bool ShouldEnableSkiaRenderer(content::W
   if (prefs->IsManagedPreference(prefs::kPdfUseSkiaRendererEnabled)) {
     return prefs->GetBoolean(prefs::kPdfUseSkiaRendererEnabled);
   }
+#endif
 
   //  When the enterprise policy is not set, use finch/feature flag choice.
   return base::FeatureList::IsEnabled(
