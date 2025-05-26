$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/perfetto/src/base/string_utils.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/perfetto/src/base/string_utils.cc
@@ -38,9 +38,10 @@ namespace base {
 
 // Locale-independant as possible version of strtod.
 double StrToD(const char* nptr, char** endptr) {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   static auto c_locale = newlocale(LC_ALL, "C", nullptr);
   return strtod_l(nptr, endptr, c_locale);
 #else
