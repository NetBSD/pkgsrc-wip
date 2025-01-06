$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/debug/proc_maps_linux.cc.orig	2024-10-18 12:33:59.758278800 +0000
+++ base/debug/proc_maps_linux.cc
@@ -18,7 +18,7 @@
 #include "base/strings/string_split.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include <inttypes.h>
 #endif
 
