$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.cc
@@ -58,7 +58,7 @@
 #include "base/strings/utf_string_conversions.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/signals_aggregator_factory.h"
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #include "components/device_signals/core/browser/signals_aggregator.h"
@@ -181,7 +181,7 @@ void RealtimeReportingClient::ReportPast
                            /*include_profile_user_name=*/false);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 void AddCrowdstrikeSignalsToEvent(
     base::Value::Dict& event,
@@ -217,7 +217,7 @@ std::string RealtimeReportingClient::Get
   username_ =
       identity_manager_ ? GetProfileEmail(identity_manager_) : std::string();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (username_.empty()) {
     username_ = Profile::FromBrowserContext(context_)->GetPrefs()->GetString(
         enterprise_signin::prefs::kProfileUserEmail);
@@ -275,7 +275,7 @@ std::string RealtimeReportingClient::Get
   return client_id;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(notyet)
 void RealtimeReportingClient::MaybeCollectDeviceSignalsAndReportEvent(
     base::Value::Dict event,
     policy::CloudPolicyClient* client,
