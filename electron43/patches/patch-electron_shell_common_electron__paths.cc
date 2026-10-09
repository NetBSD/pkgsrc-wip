$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/common/electron_paths.cc.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/common/electron_paths.cc
@@ -12,7 +12,7 @@
 #include "shell/common/platform_util.h"
 #include "shell/common/thread_restrictions.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 
@@ -62,7 +62,7 @@ bool ElectronPathProvider(int key, base:
       create_dir = true;
       break;
     }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case DIR_APP_DATA: {
       auto env = base::Environment::Create();
       cur = base::nix::GetXDGDirectory(
