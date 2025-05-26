$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/webui/web_ui_main_frame_observer.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/webui/web_ui_main_frame_observer.cc
@@ -14,7 +14,7 @@
 #include "content/public/browser/navigation_handle.h"
 #include "content/public/browser/web_ui_controller.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/feature_list.h"
 #include "base/functional/callback_helpers.h"
 #include "base/logging.h"
@@ -32,7 +32,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Remove the pieces of the URL we don't want to send back with the error
 // reports. In particular, do not send query or fragments as those can have
 // privacy-sensitive information in them.
@@ -56,7 +56,7 @@ WebUIMainFrameObserver::WebUIMainFrameOb
 
 WebUIMainFrameObserver::~WebUIMainFrameObserver() = default;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void WebUIMainFrameObserver::OnDidAddMessageToConsole(
     RenderFrameHost* source_frame,
     blink::mojom::ConsoleMessageLevel log_level,
@@ -171,7 +171,7 @@ void WebUIMainFrameObserver::ReadyToComm
 
 // TODO(crbug.com/40149439) This is currently disabled due to Windows DLL
 // thunking issues. Fix & re-enable.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   MaybeEnableWebUIJavaScriptErrorReporting(navigation_handle);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
