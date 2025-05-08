$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -20,7 +20,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
