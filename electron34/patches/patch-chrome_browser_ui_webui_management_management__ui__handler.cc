$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/webui/management/management_ui_handler.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/webui/management/management_ui_handler.cc
@@ -58,7 +58,7 @@
 #include "ui/base/l10n/l10n_util.h"
 #include "ui/base/webui/web_ui_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/user_permission_service_factory.h"
 #include "components/device_signals/core/browser/user_permission_service.h"  // nogncheck
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -349,7 +349,7 @@ void ManagementUIHandler::AddReportingIn
       report_sources->Append(std::move(data));
     }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     auto device_signal_data = GetDeviceSignalGrantedMessage();
     if (!device_signal_data.empty()) {
       report_sources->Append(std::move(device_signal_data));
@@ -371,7 +371,7 @@ void ManagementUIHandler::AddReportingIn
       report_sources->Append(std::move(data));
     }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     auto device_signal_data = GetDeviceSignalGrantedMessage();
     if (!device_signal_data.empty()) {
       report_sources->Append(std::move(device_signal_data));
@@ -552,7 +552,7 @@ policy::PolicyService* ManagementUIHandl
       ->policy_service();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 device_signals::UserPermissionService*
 ManagementUIHandler::GetUserPermissionService() {
   return enterprise_signals::UserPermissionServiceFactory::GetForProfile(
