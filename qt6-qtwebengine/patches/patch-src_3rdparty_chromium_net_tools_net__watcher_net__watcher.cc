$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/tools/net_watcher/net_watcher.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/net/tools/net_watcher/net_watcher.cc
@@ -32,7 +32,7 @@
 #include "net/proxy_resolution/proxy_config_service.h"
 #include "net/proxy_resolution/proxy_config_with_annotation.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "net/base/network_change_notifier_linux.h"
 #endif
 
@@ -44,7 +44,7 @@ namespace {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Flag to specifies which network interfaces to ignore. Interfaces should
 // follow as a comma seperated list.
 const char kIgnoreNetifFlag[] = "ignore-netif";
@@ -163,7 +163,7 @@ int main(int argc, char* argv[]) {
 
   NetWatcher net_watcher;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
   std::string ignored_netifs_str =
       command_line->GetSwitchValueASCII(kIgnoreNetifFlag);
