$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/i18n/icu_util.cc.orig	2024-10-18 12:33:59.770272300 +0000
+++ base/i18n/icu_util.cc
@@ -52,7 +52,7 @@
 #include "third_party/icu/source/common/unicode/unistr.h"
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 #endif
@@ -328,7 +328,7 @@ void InitializeIcuTimeZone() {
       FuchsiaIntlProfileWatcher::GetPrimaryTimeZoneIdForIcuInitialization();
   icu::TimeZone::adoptDefault(
       icu::TimeZone::createTimeZone(icu::UnicodeString::fromUTF8(zone_id)));
-#elif BUILDFLAG(IS_CHROMEOS) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
+#elif BUILDFLAG(IS_CHROMEOS) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_BSD)
   // To respond to the time zone change properly, the default time zone
   // cache in ICU has to be populated on starting up.
   // See TimeZoneMonitorLinux::NotifyClientsFromImpl().
