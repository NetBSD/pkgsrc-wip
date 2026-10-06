$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/webui/accessibility/accessibility_ui.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/webui/accessibility/accessibility_ui.cc
@@ -48,6 +48,7 @@
 #include "content/public/browser/web_contents.h"
 #include "content/public/browser/web_contents_delegate.h"
 #include "content/public/browser/web_ui_data_source.h"
+#include "electron/shell/browser/electron_browser_context.h"
 #include "ui/accessibility/accessibility_features.h"
 #include "ui/accessibility/ax_updates_and_events.h"
 #include "ui/accessibility/platform/ax_platform_node.h"
@@ -174,7 +175,7 @@ base::Value::Dict BuildTargetDescriptor(
                                accessibility_mode);
 }
 
-#if !BUILDFLAG(IS_ANDROID)
+#if 0
 base::Value::Dict BuildTargetDescriptor(Browser* browser) {
   base::Value::Dict target_data;
   target_data.Set(kSessionIdField, browser->session_id().id());
@@ -208,7 +209,7 @@ void HandleAccessibilityRequestCallback(
   DCHECK(ShouldHandleAccessibilityRequestCallback(path));
 
   base::Value::Dict data;
-  PrefService* pref = Profile::FromBrowserContext(current_context)->GetPrefs();
+  PrefService* pref = static_cast<electron::ElectronBrowserContext*>(current_context)->prefs();
   ui::AXMode mode =
       content::BrowserAccessibilityState::GetInstance()->GetAccessibilityMode();
   bool is_native_enabled = content::BrowserAccessibilityState::GetInstance()
@@ -241,7 +242,7 @@ void HandleAccessibilityRequestCallback(
   data.Set(kViewsAccessibility, features::IsAccessibilityTreeForViewsEnabled());
 
   std::string pref_api_type =
-      pref->GetString(prefs::kShownAccessibilityApiType);
+      std::string(pref->GetString(prefs::kShownAccessibilityApiType));
   bool pref_api_type_supported = false;
 
   std::vector<ui::AXApiType::Type> supported_api_types =
@@ -308,11 +309,11 @@ void HandleAccessibilityRequestCallback(
   data.Set(kPagesField, std::move(page_list));
 
   base::Value::List browser_list;
-#if !BUILDFLAG(IS_ANDROID)
+#if 0
   for (Browser* browser : *BrowserList::GetInstance()) {
     browser_list.Append(BuildTargetDescriptor(browser));
   }
-#endif  // !BUILDFLAG(IS_ANDROID)
+#endif
   data.Set(kBrowsersField, std::move(browser_list));
 
   base::Value::List widgets_list;
@@ -645,7 +646,8 @@ void AccessibilityUIMessageHandler::SetG
   const std::string value = CheckJSValue(data.FindString(kValueField));
 
   if (string_name == kApiTypeField) {
-    PrefService* pref = Profile::FromWebUI(web_ui())->GetPrefs();
+    PrefService* pref = static_cast<electron::ElectronBrowserContext*>(
+            web_ui()->GetWebContents()->GetBrowserContext())->prefs();
     pref->SetString(prefs::kShownAccessibilityApiType, value);
   }
 }
@@ -698,7 +700,8 @@ void AccessibilityUIMessageHandler::Requ
                      AXPropertyFilter::ALLOW_EMPTY);
   AddPropertyFilters(property_filters, deny, AXPropertyFilter::DENY);
 
-  PrefService* pref = Profile::FromWebUI(web_ui())->GetPrefs();
+  PrefService* pref = static_cast<electron::ElectronBrowserContext*>(
+              web_contents->GetBrowserContext())->prefs();
   ui::AXApiType::Type api_type =
       ui::AXApiType::From(pref->GetString(prefs::kShownAccessibilityApiType));
   std::string accessibility_contents =
@@ -725,6 +728,7 @@ void AccessibilityUIMessageHandler::Requ
                      AXPropertyFilter::ALLOW_EMPTY);
   AddPropertyFilters(property_filters, deny, AXPropertyFilter::DENY);
 
+#if 0
   for (Browser* browser : *BrowserList::GetInstance()) {
     if (browser->session_id().id() == session_id) {
       base::Value::Dict result = BuildTargetDescriptor(browser);
@@ -737,6 +741,7 @@ void AccessibilityUIMessageHandler::Requ
       return;
     }
   }
+#endif
 #endif  // !BUILDFLAG(IS_ANDROID)
   // No browser with the specified |session_id| was found.
   base::Value::Dict result;
@@ -805,11 +810,13 @@ void AccessibilityUIMessageHandler::Stop
 }
 
 ui::AXApiType::Type AccessibilityUIMessageHandler::GetRecordingApiType() {
-  PrefService* pref = Profile::FromWebUI(web_ui())->GetPrefs();
-  const std::vector<ui::AXApiType::Type> supported_types =
-      content::AXInspectFactory::SupportedApis();
+  PrefService* pref = static_cast<electron::ElectronBrowserContext*>(
+            web_ui()->GetWebContents()->GetBrowserContext())->prefs();
   ui::AXApiType::Type api_type =
       ui::AXApiType::From(pref->GetString(prefs::kShownAccessibilityApiType));
+
+  const std::vector<ui::AXApiType::Type> supported_types =
+      content::AXInspectFactory::SupportedApis();
   // Check to see if it is in the supported types list.
   if (std::find(supported_types.begin(), supported_types.end(), api_type) ==
       supported_types.end()) {
@@ -879,8 +886,11 @@ void AccessibilityUIMessageHandler::Requ
 // static
 void AccessibilityUIMessageHandler::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
+#if 0
   const std::string_view default_api_type =
       std::string_view(ui::AXApiType::Type(ui::AXApiType::kBlink));
   registry->RegisterStringPref(prefs::kShownAccessibilityApiType,
                                std::string(default_api_type));
+  registry->RegisterBooleanPref(prefs::kShowInternalAccessibilityTree, false);
+#endif
 }
