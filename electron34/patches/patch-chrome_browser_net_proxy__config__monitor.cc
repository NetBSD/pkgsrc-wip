$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/net/proxy_config_monitor.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/net/proxy_config_monitor.cc
@@ -11,7 +11,9 @@
 #include "build/chromeos_buildflags.h"
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/net/proxy_service_factory.h"
+#if 0
 #include "chrome/browser/profiles/profile.h"
+#endif
 #include "components/proxy_config/pref_proxy_config_tracker_impl.h"
 #include "content/public/browser/browser_thread.h"
 #include "mojo/public/cpp/bindings/pending_remote.h"
@@ -21,12 +23,13 @@
 #include "chrome/browser/ash/profiles/profile_helper.h"
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(ENABLE_EXTENSIONS)
+#if 0
 #include "chrome/browser/extensions/api/proxy/proxy_api.h"
 #endif
 
 using content::BrowserThread;
 
+#if 0
 ProxyConfigMonitor::ProxyConfigMonitor(Profile* profile) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
   DCHECK(profile);
@@ -57,6 +60,7 @@ ProxyConfigMonitor::ProxyConfigMonitor(P
 
   proxy_config_service_->AddObserver(this);
 }
+#endif
 
 ProxyConfigMonitor::ProxyConfigMonitor(PrefService* local_state) {
   DCHECK(BrowserThread::CurrentlyOn(BrowserThread::UI) ||
@@ -135,8 +139,10 @@ void ProxyConfigMonitor::OnLazyProxyConf
 void ProxyConfigMonitor::OnPACScriptError(int32_t line_number,
                                           const std::string& details) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
+#if 0
   extensions::ProxyEventRouter::GetInstance()->OnPACScriptError(
       profile_, line_number, base::UTF8ToUTF16(details));
+#endif
 }
 
 void ProxyConfigMonitor::OnRequestMaybeFailedDueToProxySettings(
@@ -151,7 +157,9 @@ void ProxyConfigMonitor::OnRequestMaybeF
     return;
   }
 
+#if 0
   extensions::ProxyEventRouter::GetInstance()->OnProxyError(profile_,
                                                             net_error);
+#endif
 }
 #endif
