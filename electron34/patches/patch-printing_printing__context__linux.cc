$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- printing/printing_context_linux.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ printing/printing_context_linux.cc
@@ -23,7 +23,7 @@
 #endif
 
 // Avoid using LinuxUi on Fuchsia.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -66,7 +66,7 @@ mojom::ResultCode PrintingContextLinux::
 
   ResetSettings();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ui::LinuxUi::instance())
     return mojom::ResultCode::kSuccess;
 
@@ -82,7 +82,7 @@ mojom::ResultCode PrintingContextLinux::
 }
 
 gfx::Size PrintingContextLinux::GetPdfPaperSizeDeviceUnits() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (ui::LinuxUi::instance())
     return ui::LinuxUi::instance()->GetPdfPaperSize(this);
 #endif
@@ -95,7 +95,7 @@ mojom::ResultCode PrintingContextLinux::
   DCHECK(!printer_settings.show_system_dialog);
   DCHECK(!in_print_job_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ui::LinuxUi::instance())
     return mojom::ResultCode::kSuccess;
 
