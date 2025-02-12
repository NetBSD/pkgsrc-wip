$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp
@@ -18,7 +18,7 @@
 #include "third_party/base/check.h"
 
 #if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !defined(OS_FUCHSIA) && \
-    !defined(OS_ASMJS)
+    !defined(OS_ASMJS) && !BUILDFLAG(IS_BSD)
 #error "Included on the wrong platform"
 #endif
 
@@ -166,9 +166,8 @@ class CLinuxPlatform : public CFX_GEModu
   std::unique_ptr<SystemFontInfoIface> CreateDefaultSystemFontInfo() override {
     auto pInfo = std::make_unique<CFX_LinuxFontInfo>();
     if (!pInfo->ParseFontCfg(CFX_GEModule::Get()->GetUserFontPaths())) {
-      pInfo->AddPath("/usr/share/fonts");
-      pInfo->AddPath("/usr/share/X11/fonts/Type1");
-      pInfo->AddPath("/usr/share/X11/fonts/TTF");
+      pInfo->AddPath("/usr/X11R6/lib/X11/fonts/Type1");
+      pInfo->AddPath("/usr/X11R6/lib/X11/fonts/TTF");
       pInfo->AddPath("/usr/local/share/fonts");
     }
     return pInfo;
