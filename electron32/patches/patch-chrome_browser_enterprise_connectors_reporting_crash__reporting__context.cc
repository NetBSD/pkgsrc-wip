$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2024-10-18 12:34:01.493305000 +0000
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -19,7 +19,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
