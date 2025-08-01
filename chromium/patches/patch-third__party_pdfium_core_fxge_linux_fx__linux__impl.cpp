$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp.orig	2025-07-21 19:32:31.000000000 +0000
+++ third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp
@@ -19,7 +19,7 @@
 #include "core/fxge/fx_font.h"
 #include "core/fxge/systemfontinfo_iface.h"
 
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !defined(OS_ASMJS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !defined(OS_ASMJS) && !BUILDFLAG(IS_BSD)
 #error "Included on the wrong platform"
 #endif
 
@@ -179,10 +179,9 @@ class CLinuxPlatform : public CFX_GEModu
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
