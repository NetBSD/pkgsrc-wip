$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/printing/browser/print_manager.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/printing/browser/print_manager.cc
@@ -47,6 +47,8 @@ void PrintManager::IsPrintingEnabled(IsP
   std::move(callback).Run(true);
 }
 
+void PrintManager::ShowInvalidPrinterSettingsError() {}
+
 void PrintManager::PrintingFailed(int32_t cookie,
                                   mojom::PrintFailureReason reason) {
   // Note: Not redundant with cookie checks in the same method in other parts of
