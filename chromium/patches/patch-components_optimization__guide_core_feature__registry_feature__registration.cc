$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/optimization_guide/core/feature_registry/feature_registration.cc.orig	2025-09-29 17:05:47.000000000 +0000
+++ components/optimization_guide/core/feature_registry/feature_registration.cc
@@ -75,7 +75,7 @@ BASE_FEATURE(kProductSpecificationsMqlsL
 BASE_FEATURE(kFormsClassificationsMqlsLogging,
              "FormsClassificationsMqlsLogging",
              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||
-                     BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+                     BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
                  ? base::FEATURE_ENABLED_BY_DEFAULT
                  : base::FEATURE_DISABLED_BY_DEFAULT);
 
