$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/flag_descriptions.cc.orig	2024-10-18 12:34:01.617235700 +0000
+++ chrome/browser/flag_descriptions.cc
@@ -419,7 +419,7 @@ const char kIsolatedSandboxedIframesDesc
     "grouping when enabled is per-site.";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kAutofillEnableAmountExtractionDesktopName[] =
     "Enable checkout amount extraction on Chrome desktop";
 const char kAutofillEnableAmountExtractionDesktopDescription[] =
@@ -856,7 +856,7 @@ const char kDevicePostureDescription[] =
     "Enables Device Posture API (foldable devices)";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kDocumentPictureInPictureAnimateResizeName[] =
     "Document Picture-in-Picture Animate Resize";
 const char kDocumentPictureInPictureAnimateResizeDescription[] =
@@ -3050,7 +3050,7 @@ const char kCbdTimeframeRequiredDescript
     "value to the list.";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 const char kPolicyIndicationForManagedDefaultSearchName[] =
     "Enable policy indication for managed Default Search provider";
 const char kPolicyIndicationForManagedDefaultSearchDescription[] =
@@ -3385,7 +3385,7 @@ const char kShowAutofillTypePredictionsD
     "text.";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kShowFeaturedEnterpriseSiteSearchName[] =
     "Show featured Enterprise site search engines in Omnibox";
 const char kShowFeaturedEnterpriseSiteSearchDescription[] =
@@ -3422,7 +3422,7 @@ const char kSiteInstanceGroupsForDataUrl
     "but in the same SiteInstanceGroup, and thus the same process.";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kSiteSearchSettingsPolicyName[] = "Enable SiteSearchSettings policy";
 const char kSiteSearchSettingsPolicyDescription[] =
     "Allow site search engines to be defined by the SiteSearchSettings policy.";
@@ -7869,7 +7869,7 @@ const char kLacrosMergeIcuDataFileDescri
     "Enables sharing common areas of icudtl.dat between Ash and Lacros.";
 #endif  // #if BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kGetAllScreensMediaName[] = "GetAllScreensMedia API";
 const char kGetAllScreensMediaDescription[] =
     "When enabled, the getAllScreensMedia API for capturing multiple screens "
@@ -8126,7 +8126,7 @@ const char kV4L2FlatStatefulVideoDecoder
 
 // Linux -----------------------------------------------------------------------
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kOzonePlatformHintChoiceDefault[] = "Default";
 const char kOzonePlatformHintChoiceAuto[] = "Auto";
 const char kOzonePlatformHintChoiceX11[] = "X11";
@@ -8156,6 +8156,20 @@ const char kSimplifiedTabDragUIDescripti
 const char kWaylandPerWindowScalingName[] = "Wayland per-window scaling";
 const char kWaylandPerWindowScalingDescription[] =
     "Enable Wayland's per-window scaling experimental support.";
+
+#if BUILDFLAG(IS_BSD)
+const char kAudioBackendName[] =
+    "Audio Backend";
+const char kAudioBackendDescription[] =
+#if BUILDFLAG(IS_OPENBSD)
+    "Select the desired audio backend to use. The default is sndio.";
+#elif BUILDFLAG(IS_NETBSD)
+    "Select the desired audio backend to use. The default is audioio.";
+#elif BUILDFLAG(IS_FREEBSD)
+    "Select the desired audio backend to use. The default will automatically "
+    "enumerate through the supported backends.";
+#endif
+#endif
 #endif  // BUILDFLAG(IS_LINUX)
 
 // All views-based platforms --------------------------------------------------
@@ -8182,14 +8196,14 @@ const char kZeroCopyVideoCaptureDescript
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kFollowingFeedSidepanelName[] = "Following feed in the sidepanel";
 const char kFollowingFeedSidepanelDescription[] =
     "Enables the following feed in the sidepanel.";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         //  BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kEnableNetworkServiceSandboxName[] =
     "Enable the network service sandbox.";
 const char kEnableNetworkServiceSandboxDescription[] =
@@ -8221,7 +8235,7 @@ const char kWebBluetoothConfirmPairingSu
     "Bluetooth";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kSkipUndecryptablePasswordsName[] =
     "Skip undecryptable passwords to use the available decryptable "
     "passwords.";
@@ -8375,7 +8389,7 @@ const char kElementCaptureDescription[] 
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kUIDebugToolsName[] = "Debugging tools for UI";
 const char kUIDebugToolsDescription[] =
     "Enables additional keyboard shortcuts to help debugging.";
@@ -8449,7 +8463,7 @@ const char kAutofillCaretExtractionDescr
     "Enables passing caret position via Autofill";
 #endif  // BUILDFLAG(ENABLE_COMPOSE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kThirdPartyProfileManagementName[] =
     "Third party profile management";
 const char kThirdPartyProfileManagementDescription[] =
