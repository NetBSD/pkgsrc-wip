$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/utility/utility_blink_platform_with_sandbox_support_impl.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/content/utility/utility_blink_platform_with_sandbox_support_impl.h
@@ -33,7 +33,7 @@ class UtilityBlinkPlatformWithSandboxSup
   blink::WebSandboxSupport* GetSandboxSupport() override;
 
  private:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 };
