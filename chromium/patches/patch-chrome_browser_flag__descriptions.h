$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/flag_descriptions.h.orig	2024-10-26 06:59:56.896716400 +0000
+++ chrome/browser/flag_descriptions.h
@@ -297,7 +297,7 @@ extern const char kImprovedSigninUIOnDes
 extern const char kImprovedSigninUIOnDesktopDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kAutofillEnableAmountExtractionDesktopName[];
 extern const char kAutofillEnableAmountExtractionDesktopDescription[];
 #endif
@@ -715,7 +715,7 @@ extern const char kDevicePostureName[];
 extern const char kDevicePostureDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kDocumentPictureInPictureAnimateResizeName[];
 extern const char kDocumentPictureInPictureAnimateResizeDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
@@ -2022,7 +2022,7 @@ extern const char kShowAutofillTypePredi
 extern const char kShowAutofillTypePredictionsDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kShowFeaturedEnterpriseSiteSearchName[];
 extern const char kShowFeaturedEnterpriseSiteSearchDescription[];
 
@@ -2044,7 +2044,7 @@ extern const char kSiteInstanceGroupsFor
 extern const char kSiteInstanceGroupsForDataUrlsDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kSiteSearchSettingsPolicyName[];
 extern const char kSiteSearchSettingsPolicyDescription[];
 
@@ -4576,7 +4576,7 @@ extern const char kBlinkExtensionDiagnos
 extern const char kBlinkExtensionDiagnosticsDescription[];
 #endif  // #if BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kGetAllScreensMediaName[];
 extern const char kGetAllScreensMediaDescription[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -4713,7 +4713,7 @@ extern const char kV4L2FlatStatefulVideo
 
 // Linux ---------------------------------------------------------------------
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kOzonePlatformHintChoiceDefault[];
 extern const char kOzonePlatformHintChoiceAuto[];
 extern const char kOzonePlatformHintChoiceX11[];
@@ -4735,6 +4735,9 @@ extern const char kWaylandPerWindowScali
 
 extern const char kWaylandTextInputV3Name[];
 extern const char kWaylandTextInputV3Description[];
+
+extern const char kAudioBackendName[];
+extern const char kAudioBackendDescription[];
 #endif  // BUILDFLAG(IS_LINUX)
 
 // All views-based platforms --------------------------------------------------
@@ -4764,7 +4767,7 @@ extern const char kWebBluetoothConfirmPa
 extern const char kWebBluetoothConfirmPairingSupportDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kSkipUndecryptablePasswordsName[];
 extern const char kSkipUndecryptablePasswordsDescription[];
 
@@ -4780,7 +4783,7 @@ extern const char kScreenlockReauthPromo
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kFollowingFeedSidepanelName[];
 extern const char kFollowingFeedSidepanelDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
@@ -4791,7 +4794,7 @@ extern const char kTaskManagerDesktopRef
 extern const char kTaskManagerDesktopRefreshDescription[];
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kEnableNetworkServiceSandboxName[];
 extern const char kEnableNetworkServiceSandboxDescription[];
 
@@ -4888,7 +4891,7 @@ extern const char kElementCaptureDescrip
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kUIDebugToolsName[];
 extern const char kUIDebugToolsDescription[];
 #endif
@@ -4942,7 +4945,7 @@ extern const char kAutofillCaretExtracti
 extern const char kAutofillCaretExtractionDescription[];
 #endif  // BUILDFLAG(ENABLE_COMPOSE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kThirdPartyProfileManagementName[];
 extern const char kThirdPartyProfileManagementDescription[];
 
@@ -4998,7 +5001,7 @@ extern const char kEnableCertManagementV
 extern const char kEnableCertManagementV2UIDescription[];
 #endif  // BUILDFLAG(CHROME_ROOT_STORE_CERT_MANAGEMENT_UI)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kSupervisedProfileHideGuestName[];
 extern const char kSupervisedProfileHideGuestDescription[];
 
