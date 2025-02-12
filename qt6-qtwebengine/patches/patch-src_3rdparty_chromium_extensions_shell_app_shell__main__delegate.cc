$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/extensions/shell/app/shell_main_delegate.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/extensions/shell/app/shell_main_delegate.cc
@@ -43,7 +43,7 @@
 #if BUILDFLAG(IS_WIN)
 #include "base/base_paths_win.h"
 #include "base/process/process_info.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #elif BUILDFLAG(IS_MAC)
 #include "base/base_paths_mac.h"
@@ -62,7 +62,7 @@ base::FilePath GetDataPath() {
     return cmd_line->GetSwitchValuePath(switches::kContentShellDataPath);
 
   base::FilePath data_dir;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   data_dir = base::nix::GetXDGDirectory(
       env.get(), base::nix::kXdgConfigHomeEnvVar, base::nix::kDotConfigDir);
