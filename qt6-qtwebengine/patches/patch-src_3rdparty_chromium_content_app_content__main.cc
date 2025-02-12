$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/app/content_main.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/content/app/content_main.cc
@@ -64,7 +64,7 @@
 #include "content/common/shared_file_util.h"
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/scoped_file.h"
 #endif
 
@@ -209,7 +209,7 @@ RunContentProcess(ContentMainParams para
     base::EnableTerminationOnOutOfMemory();
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
