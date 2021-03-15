$NetBSD$

--- src/3rdparty/chromium/third_party/pdfium/xfa/fgas/font/cfx_fontsourceenum_file.cpp.orig	2020-07-15 19:01:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/pdfium/xfa/fgas/font/cfx_fontsourceenum_file.cpp
@@ -20,6 +20,7 @@ constexpr const char* kFontFolders[] = {
     "/usr/share/X11/fonts/Type1",
     "/usr/share/X11/fonts/TTF",
     "/usr/local/share/fonts",
+    "@X11BASE@/share/fonts",
 #elif defined(OS_MACOSX)
     "~/Library/Fonts",
     "/Library/Fonts",
