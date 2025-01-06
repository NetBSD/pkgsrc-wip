$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/native_window.cc.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/shell/browser/native_window.cc
@@ -203,7 +203,7 @@ void NativeWindow::InitFromOptions(const
   } else {
     SetSizeConstraints(size_constraints);
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool closable;
   if (options.Get(options::kClosable, &closable)) {
     SetClosable(closable);
