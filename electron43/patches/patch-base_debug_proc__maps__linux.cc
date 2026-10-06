$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/debug/proc_maps_linux.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/debug/proc_maps_linux.cc
@@ -20,7 +20,7 @@
 #include "base/strings/string_split.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include <inttypes.h>
 #endif
 
