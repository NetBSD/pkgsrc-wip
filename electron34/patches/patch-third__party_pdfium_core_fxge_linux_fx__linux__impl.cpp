$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp
@@ -20,7 +20,7 @@
 #include "core/fxge/fx_font.h"
 #include "core/fxge/systemfontinfo_iface.h"
 
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !defined(OS_ASMJS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !defined(OS_ASMJS) && !BUILDFLAG(IS_BSD)
 #error "Included on the wrong platform"
 #endif
 
@@ -173,10 +173,9 @@ class CLinuxPlatform : public CFX_GEModu
   std::unique_ptr<SystemFontInfoIface> CreateDefaultSystemFontInfo() override {
     auto pInfo = std::make_unique<CFX_LinuxFontInfo>();
     if (!pInfo->ParseFontCfg(CFX_GEModule::Get()->GetUserFontPaths())) {
-      pInfo->AddPath("/usr/share/fonts");
-      pInfo->AddPath("/usr/share/X11/fonts/Type1");
-      pInfo->AddPath("/usr/share/X11/fonts/TTF");
-      pInfo->AddPath("/usr/local/share/fonts");
+      pInfo->AddPath("@X11BASE@/lib/X11/fonts/Type1");
+      pInfo->AddPath("@X11BASE@/lib/X11/fonts/TTF");
+      pInfo->AddPath("@PREFIX@/share/fonts");
     }
     return pInfo;
   }
