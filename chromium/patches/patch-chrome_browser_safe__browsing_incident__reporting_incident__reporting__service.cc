$NetBSD$

--- chrome/browser/safe_browsing/incident_reporting/incident_reporting_service.cc.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/safe_browsing/incident_reporting/incident_reporting_service.cc
@@ -672,7 +672,7 @@ void IncidentReportingService::OnEnviron
   environment_collection_pending_ = false;
 
 // Process::Current().CreationTime() is missing on some platforms.
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   base::TimeDelta uptime =
       first_incident_time_ - base::Process::Current().CreationTime();
   environment_data->mutable_process()->set_uptime_msec(uptime.InMilliseconds());
