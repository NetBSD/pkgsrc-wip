$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/native_window.cc.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/shell/browser/native_window.cc
@@ -200,7 +200,7 @@ void NativeWindow::InitFromOptions(const
   } else {
     SetSizeConstraints(size_constraints);
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool closable;
   if (options.Get(options::kClosable, &closable)) {
     SetClosable(closable);
