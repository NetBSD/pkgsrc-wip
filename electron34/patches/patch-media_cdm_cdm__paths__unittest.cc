$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/cdm/cdm_paths_unittest.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ media/cdm/cdm_paths_unittest.cc
@@ -27,7 +27,7 @@ const char kComponentPlatform[] =
     "win";
 #elif BUILDFLAG(IS_CHROMEOS)
     "cros";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     "linux";
 #elif BUILDFLAG(IS_FUCHSIA)
     "fuchsia";
