$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/exclusive_access/fullscreen_controller.h.orig	2024-10-18 12:34:03.160379400 +0000
+++ chrome/browser/ui/exclusive_access/fullscreen_controller.h
@@ -250,10 +250,12 @@ class FullscreenController : public Excl
   // Used in testing to set the state to tab fullscreen.
   bool is_tab_fullscreen_for_testing_ = false;
 
+#if 0
   // Tracks related popups that lost activation or were shown without activation
   // during content fullscreen sessions. This also activates the popups when
   // fullscreen exits, to prevent sites from creating persistent popunders.
   std::unique_ptr<PopunderPreventer> popunder_preventer_;
+#endif
 
   base::ObserverList<FullscreenObserver> observer_list_;
 
