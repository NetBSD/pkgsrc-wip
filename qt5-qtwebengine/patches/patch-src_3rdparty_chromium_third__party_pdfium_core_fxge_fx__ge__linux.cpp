$NetBSD$

--- src/3rdparty/chromium/third_party/pdfium/core/fxge/fx_ge_linux.cpp.orig	2020-07-15 19:01:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/pdfium/core/fxge/fx_ge_linux.cpp
@@ -159,6 +159,7 @@ std::unique_ptr<SystemFontInfoIface> Sys
     pInfo->AddPath("/usr/share/X11/fonts/Type1");
     pInfo->AddPath("/usr/share/X11/fonts/TTF");
     pInfo->AddPath("/usr/local/share/fonts");
+    pInfo->AddPath("@X11BASE@/share/fonts");
   }
   return std::move(pInfo);
 }
