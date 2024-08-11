$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/ppapi_plugin/ppapi_blink_platform_impl.h.orig	2024-07-24 02:44:37.572872200 +0000
+++ content/ppapi_plugin/ppapi_blink_platform_impl.h
@@ -36,7 +36,7 @@ class PpapiBlinkPlatformImpl : public Bl
   blink::WebString DefaultLocale() override;
 
  private:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 };
