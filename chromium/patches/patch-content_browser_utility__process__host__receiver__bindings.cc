$NetBSD: patch-content_browser_utility__process__host__receiver__bindings.cc,v 1.1 2025/02/06 09:58:06 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/utility_process_host_receiver_bindings.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/utility_process_host_receiver_bindings.cc
@@ -10,13 +10,13 @@
 #include "content/public/browser/content_browser_client.h"
 #include "content/public/common/content_client.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
 #include "content/browser/font_service.h"  // nogncheck
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "components/viz/host/gpu_client.h"
 #include "content/public/browser/gpu_client.h"
 #endif
@@ -25,14 +25,14 @@ namespace content {
 
 void UtilityProcessHost::BindHostReceiver(
     mojo::GenericPendingReceiver receiver) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
     ConnectToFontService(std::move(font_receiver));
     return;
   }
 #endif
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (allowed_gpu_) {
     // TODO(crbug.com/328099369) Remove once all clients get this directly.
     if (auto gpu_receiver = receiver.As<viz::mojom::Gpu>()) {
