$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/printing/browser/print_manager.cc.orig	2024-10-18 12:34:07.561984000 +0000
+++ components/printing/browser/print_manager.cc
@@ -47,6 +47,8 @@ void PrintManager::IsPrintingEnabled(IsP
   std::move(callback).Run(true);
 }
 
+void PrintManager::ShowInvalidPrinterSettingsError() {}
+
 void PrintManager::PrintingFailed(int32_t cookie,
                                   mojom::PrintFailureReason reason) {
   // Note: Not redundant with cookie checks in the same method in other parts of
