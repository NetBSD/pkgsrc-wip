$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/native_window.cc.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/browser/native_window.cc
@@ -33,7 +33,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "shell/browser/ui/views/frameless_view.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/ui/views/electron_frame_view_linux.h"
 #endif
 
@@ -185,7 +185,7 @@ void NativeWindow::InitFromOptions(const
   } else if (bool center; options.Get(options::kCenter, &center) && center) {
     Center();
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (bool val; options.Get(options::kClosable, &val))
     SetClosable(val);
 #endif
