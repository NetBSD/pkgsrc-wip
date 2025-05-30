$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/autofill/payments/desktop_payments_window_manager.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/autofill/payments/desktop_payments_window_manager.h
@@ -14,7 +14,7 @@
 #include "components/autofill/core/browser/payments/payments_window_manager.h"
 #include "content/public/browser/web_contents_observer.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/scoped_observation.h"
 #include "chrome/browser/ui/browser_list.h"
 #include "chrome/browser/ui/browser_list_observer.h"
@@ -39,7 +39,7 @@ class PaymentsWindowUserConsentDialogCon
 // WebContents of the original tab that the pop-up is created in. If there is a
 // pop-up currently present, `this` will observe the WebContents of that pop-up.
 class DesktopPaymentsWindowManager : public PaymentsWindowManager,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                                      public BrowserListObserver,
 #endif  // BUILDFLAG(IS_LINUX)
                                      public content::WebContentsObserver {
@@ -58,7 +58,7 @@ class DesktopPaymentsWindowManager : pub
       content::NavigationHandle* navigation_handle) override;
   void WebContentsDestroyed() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // BrowserListObserver:
   void OnBrowserSetLastActive(Browser* browser) override;
 #endif  // BUILDFLAG(IS_LINUX)
@@ -136,7 +136,7 @@ class DesktopPaymentsWindowManager : pub
   std::unique_ptr<PaymentsWindowUserConsentDialogControllerImpl>
       payments_window_user_consent_dialog_controller_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<BrowserList, BrowserListObserver> scoped_observation_{
       this};
 #endif  // BUILDFLAG(IS_LINUX)
