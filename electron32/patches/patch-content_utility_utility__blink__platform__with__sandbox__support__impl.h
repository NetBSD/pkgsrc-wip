$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/utility/utility_blink_platform_with_sandbox_support_impl.h.orig	2024-10-18 12:34:16.205466700 +0000
+++ content/utility/utility_blink_platform_with_sandbox_support_impl.h
@@ -33,7 +33,7 @@ class UtilityBlinkPlatformWithSandboxSup
   blink::WebSandboxSupport* GetSandboxSupport() override;
 
  private:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 };
