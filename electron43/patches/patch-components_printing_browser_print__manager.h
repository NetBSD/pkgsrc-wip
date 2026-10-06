$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/printing/browser/print_manager.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/printing/browser/print_manager.h
@@ -48,6 +48,7 @@ class PrintManager : public content::Web
                         DidPrintDocumentCallback callback) override;
   void IsPrintingEnabled(IsPrintingEnabledCallback callback) override;
   void DidShowPrintDialog() override;
+  void ShowInvalidPrinterSettingsError() override;
   void PrintingFailed(int32_t cookie,
                       mojom::PrintFailureReason reason) override;
 
