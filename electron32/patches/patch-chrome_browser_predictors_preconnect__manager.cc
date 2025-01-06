$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/predictors/preconnect_manager.cc.orig	2024-10-18 12:34:01.861099700 +0000
+++ chrome/browser/predictors/preconnect_manager.cc
@@ -11,9 +11,11 @@
 #include "base/metrics/histogram_macros.h"
 #include "base/not_fatal_until.h"
 #include "base/trace_event/trace_event.h"
+#if 0
 #include "chrome/browser/predictors/resource_prefetch_predictor.h"
 #include "chrome/browser/preloading/preloading_prefs.h"
 #include "chrome/browser/profiles/profile.h"
+#endif
 #include "content/public/browser/browser_context.h"
 #include "content/public/browser/browser_task_traits.h"
 #include "content/public/browser/browser_thread.h"
@@ -24,6 +26,20 @@ namespace predictors {
 
 const bool kAllowCredentialsOnPreconnectByDefault = true;
 
+// NOTE(nornagon): this is copied from
+// //chrome/browser/predictors/resource_prefetch_predictor.cc we don't need
+// anything in that file other than this constructor.
+PreconnectRequest::PreconnectRequest(
+    const url::Origin& origin,
+    int num_sockets,
+    const net::NetworkAnonymizationKey& network_anonymization_key)
+    : origin(origin),
+      num_sockets(num_sockets),
+      network_anonymization_key(network_anonymization_key) {
+  DCHECK_GE(num_sockets, 0);
+  DCHECK(!network_anonymization_key.IsEmpty());
+}
+
 PreconnectedRequestStats::PreconnectedRequestStats(const url::Origin& origin,
                                                    bool was_preconnected)
     : origin(origin), was_preconnected(was_preconnected) {}
@@ -84,12 +100,15 @@ PreconnectManager::PreconnectManager(bas
 PreconnectManager::~PreconnectManager() = default;
 
 bool PreconnectManager::IsEnabled() {
+#if 0
   Profile* profile = Profile::FromBrowserContext(browser_context_);
   if (!profile) {
     return false;
   }
   return prefetch::IsSomePreloadingEnabled(*profile->GetPrefs()) ==
          content::PreloadingEligibility::kEligible;
+#endif
+  return true;
 }
 
 void PreconnectManager::Start(const GURL& url,
