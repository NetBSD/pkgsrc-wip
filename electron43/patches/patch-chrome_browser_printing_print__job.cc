$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/printing/print_job.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/printing/print_job.cc
@@ -97,6 +97,7 @@ bool PrintWithReducedRasterization(PrefS
   return base::FeatureList::IsEnabled(features::kPrintWithReducedRasterization);
 }
 
+#if 0
 PrefService* GetPrefsForWebContents(content::WebContents* web_contents) {
   // TODO(thestig): Figure out why crbug.com/1083911 occurred, which is likely
   // because `web_contents` was null. As a result, this section has many more
@@ -111,6 +112,7 @@ content::WebContents* GetWebContents(con
   auto* rfh = content::RenderFrameHost::FromID(rfh_id);
   return rfh ? content::WebContents::FromRenderFrameHost(rfh) : nullptr;
 }
+#endif
 
 #endif  // BUILDFLAG(IS_WIN)
 
@@ -151,10 +153,8 @@ void PrintJob::Initialize(std::unique_pt
 
 #if BUILDFLAG(IS_WIN)
   pdf_page_mapping_ = PageNumber::GetPages(settings->ranges(), page_count);
-  PrefService* prefs = GetPrefsForWebContents(GetWebContents(rfh_id_));
-  if (prefs && prefs->IsManagedPreference(prefs::kPdfUseSkiaRendererEnabled)) {
-    use_skia_ = prefs->GetBoolean(prefs::kPdfUseSkiaRendererEnabled);
-  }
+  // TODO(codebytere): should we enable this later?
+  use_skia_ = false;
 #endif
 
   auto new_doc = base::MakeRefCounted<PrintedDocument>(std::move(settings),
@@ -404,8 +404,10 @@ void PrintJob::StartPdfToEmfConversion(
 
   const PrintSettings& settings = document()->settings();
 
+#if 0
   PrefService* prefs = GetPrefsForWebContents(GetWebContents(rfh_id_));
-  bool print_with_reduced_rasterization = PrintWithReducedRasterization(prefs);
+#endif
+  bool print_with_reduced_rasterization = PrintWithReducedRasterization(nullptr);
 
   using RenderMode = PdfRenderSettings::Mode;
   RenderMode mode = print_with_reduced_rasterization
@@ -497,8 +499,10 @@ void PrintJob::StartPdfToPostScriptConve
   if (ps_level2) {
     mode = PdfRenderSettings::Mode::POSTSCRIPT_LEVEL2;
   } else {
+#if 0
     PrefService* prefs = GetPrefsForWebContents(GetWebContents(rfh_id_));
-    mode = PrintWithPostScriptType42Fonts(prefs)
+#endif
+    mode = PrintWithPostScriptType42Fonts(nullptr)
                ? PdfRenderSettings::Mode::POSTSCRIPT_LEVEL3_WITH_TYPE42_FONTS
                : PdfRenderSettings::Mode::POSTSCRIPT_LEVEL3;
   }
