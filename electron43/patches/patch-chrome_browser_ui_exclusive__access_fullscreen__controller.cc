$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/exclusive_access/fullscreen_controller.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/exclusive_access/fullscreen_controller.cc
@@ -20,12 +20,16 @@
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/history/history_service_factory.h"
 #include "chrome/browser/profiles/profile.h"
+#if 0
 #include "chrome/browser/ui/blocked_content/popunder_preventer.h"
+#endif
 #include "chrome/browser/ui/exclusive_access/exclusive_access_context.h"
 #include "chrome/browser/ui/exclusive_access/exclusive_access_manager.h"
 #include "chrome/browser/ui/exclusive_access/fullscreen_within_tab_helper.h"
+#if 0
 #include "chrome/browser/ui/status_bubble.h"
 #include "chrome/browser/ui/tabs/tab_strip_model.h"
+#endif
 #include "chrome/common/chrome_switches.h"
 #include "components/history/core/browser/history_service.h"
 #include "components/history/core/browser/history_types.h"
@@ -260,10 +264,12 @@ void FullscreenController::EnterFullscre
     return;
   }
 
+#if 0
   if (!popunder_preventer_)
     popunder_preventer_ = std::make_unique<PopunderPreventer>(web_contents);
   else
     popunder_preventer_->WillActivateWebContents(web_contents);
+#endif
 
   // Keep the current state. |SetTabWithExclusiveAccess| may change the return
   // value of |IsWindowFullscreenForTabOrPending|.
@@ -375,12 +381,14 @@ void FullscreenController::ExitFullscree
 void FullscreenController::FullscreenTabOpeningPopup(
     content::WebContents* opener,
     content::WebContents* popup) {
+#if 0
   if (!popunder_preventer_) {
     return;
   }
 
   DCHECK_EQ(exclusive_access_tab(), opener);
   popunder_preventer_->AddPotentialPopunder(popup);
+#endif
 }
 
 void FullscreenController::OnTabDeactivated(
@@ -466,10 +474,12 @@ void FullscreenController::FullscreenTra
 #endif  // DCHECK_IS_ON()
   tab_fullscreen_target_display_id_ = display::kInvalidDisplayId;
   started_fullscreen_transition_ = false;
+#if 0
   if (!IsTabFullscreen()) {
     // Activate any popup windows created while content fullscreen, after exit.
     popunder_preventer_.reset();
   }
+#endif
 }
 
 void FullscreenController::RunOrDeferUntilTransitionIsComplete(
@@ -577,18 +587,17 @@ void FullscreenController::EnterFullscre
   // Do not enter fullscreen mode if disallowed by pref. This prevents the user
   // from manually entering fullscreen mode and also disables kiosk mode on
   // desktop platforms.
-  if (!exclusive_access_manager()
-           ->context()
-           ->GetProfile()
-           ->GetPrefs()
-           ->GetBoolean(prefs::kFullscreenAllowed)) {
+  auto* profile = exclusive_access_manager()->context()->GetProfile();
+  if (!profile || !profile->GetPrefs()->GetBoolean(prefs::kFullscreenAllowed))
     return;
-  }
 #endif
   started_fullscreen_transition_ = true;
   toggled_into_fullscreen_ = true;
+#if 0
   bool entering_tab_fullscreen = option == TAB && !tab_fullscreen_;
+#endif
   GURL url;
+#if 0
   if (option == TAB) {
     url = GetRequestingOrigin();
     tab_fullscreen_ = true;
@@ -621,6 +630,7 @@ void FullscreenController::EnterFullscre
     if (!extension_caused_fullscreen_.is_empty())
       url = extension_caused_fullscreen_;
   }
+#endif
 
   fullscreen_start_time_ = base::TimeTicks::Now();
   if (option == BROWSER)
@@ -641,6 +651,7 @@ void FullscreenController::ExitFullscree
     return;
   }
 
+#if 0
   // `fullscreen_start_time_` is null if a fullscreen tab moves to a new window.
   if (fullscreen_start_time_ && exclusive_access_tab()) {
     ukm::SourceId source_id =
@@ -652,15 +663,16 @@ void FullscreenController::ExitFullscree
         .Record(ukm::UkmRecorder::Get());
     fullscreen_start_time_.reset();
   }
+#endif
 
   toggled_into_fullscreen_ = false;
   started_fullscreen_transition_ = true;
-#if BUILDFLAG(IS_MAC)
-  // Mac windows report a state change instantly, and so we must also clear
+
+  // Electron native windows report a state change instantly, and so we must also clear
   // state_prior_to_tab_fullscreen_ to match them else other logic using
   // state_prior_to_tab_fullscreen_ will be incorrect.
   NotifyTabExclusiveAccessLost();
-#endif
+
   exclusive_access_manager()->context()->ExitFullscreen();
   extension_caused_fullscreen_ = GURL();
   exclusive_access_manager()->UpdateBubble(base::NullCallback());
@@ -722,8 +734,12 @@ GURL FullscreenController::GetEmbeddingO
 void FullscreenController::RecordMetricsOnFullscreenApiRequested(
     content::RenderFrameHost* requesting_frame) {
   history::HistoryService* service =
+  #if 0
       HistoryServiceFactory::GetForProfileWithoutCreating(
           exclusive_access_manager()->context()->GetProfile());
+  #else
+      nullptr;
+  #endif
   if (service) {
     // Check if the origin has been visited more than a day ago and whether it's
     // on an allowlist, then record those bits of information in a metric.
