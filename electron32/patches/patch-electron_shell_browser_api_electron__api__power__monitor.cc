$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/api/electron_api_power_monitor.cc.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/shell/browser/api/electron_api_power_monitor.cc
@@ -118,6 +118,11 @@ void PowerMonitor::OnSpeedLimitChange(in
       gin::DataObjectBuilder(isolate).Set("limit", speed_limit).Build());
 }
 
+#if BUILDFLAG(IS_BSD)
+void PowerMonitor::SetListeningForShutdown(bool is_listening) {
+}
+#endif
+
 #if BUILDFLAG(IS_LINUX)
 void PowerMonitor::SetListeningForShutdown(bool is_listening) {
   if (is_listening) {
@@ -143,7 +148,7 @@ gin::ObjectTemplateBuilder PowerMonitor:
   auto builder =
       gin_helper::EventEmitterMixin<PowerMonitor>::GetObjectTemplateBuilder(
           isolate);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   builder.SetMethod("setListeningForShutdown",
                     &PowerMonitor::SetListeningForShutdown);
 #endif
