$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/common/features.cc.orig	2024-09-24 20:49:58.746518000 +0000
+++ ui/ozone/common/features.cc
@@ -30,7 +30,7 @@ BASE_FEATURE(kWaylandSurfaceSubmissionIn
 // enabled.
 BASE_FEATURE(kWaylandFractionalScaleV1,
              "WaylandFractionalScaleV1",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
