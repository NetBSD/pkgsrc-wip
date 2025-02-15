$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/net/system_network_context_manager.cc.orig	2025-01-21 17:36:55.000000000 +0000
+++ electron/shell/browser/net/system_network_context_manager.cc
@@ -42,7 +42,7 @@
 #include "shell/common/options_switches.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/os_crypt/sync/key_storage_config_linux.h"
 #endif
 
