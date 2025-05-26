$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/usb/usb_chooser_controller.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/usb/usb_chooser_controller.cc
@@ -99,8 +99,8 @@ UsbChooserController::UsbChooserControll
           CreateChooserTitle(render_frame_host, IDS_USB_DEVICE_CHOOSER_PROMPT)),
       options_(std::move(options)),
       callback_(std::move(callback)),
-      requesting_frame_(render_frame_host) {
-  RenderFrameHost* main_frame = requesting_frame_->GetMainFrame();
+      render_frame_host_id_(render_frame_host->GetGlobalId()) {
+  RenderFrameHost* main_frame = render_frame_host->GetMainFrame();
   origin_ = main_frame->GetLastCommittedOrigin();
   Profile* profile =
       Profile::FromBrowserContext(main_frame->GetBrowserContext());
@@ -202,7 +202,15 @@ void UsbChooserController::Cancel() {
 void UsbChooserController::Close() {}
 
 void UsbChooserController::OpenHelpCenterUrl() const {
-  WebContents::FromRenderFrameHost(requesting_frame_)
+  content::RenderFrameHost* render_frame_host =
+      content::RenderFrameHost::FromID(render_frame_host_id_);
+  if (!render_frame_host) {
+    // When |render_frame_host| is not valid anymore we don't want to open help
+    // center url.
+    return;
+  }
+
+  WebContents::FromRenderFrameHost(render_frame_host)
       ->OpenURL(content::OpenURLParams(
                     GURL(chrome::kChooserUsbOverviewURL), content::Referrer(),
                     WindowOpenDisposition::NEW_FOREGROUND_TAB,
@@ -266,6 +274,14 @@ void UsbChooserController::GotUsbDeviceL
 
 bool UsbChooserController::DisplayDevice(
     const device::mojom::UsbDeviceInfo& device_info) const {
+  content::RenderFrameHost* render_frame_host =
+      content::RenderFrameHost::FromID(render_frame_host_id_);
+  if (!render_frame_host) {
+    // When |render_frame_host| is not valid anymore we don't want to display
+    // any device information.
+    return false;
+  }
+
   if (!device::UsbDeviceFilterMatchesAny(options_->filters, device_info)) {
     return false;
   }
@@ -280,10 +296,9 @@ bool UsbChooserController::DisplayDevice
   bool is_usb_unrestricted = false;
   if (base::FeatureList::IsEnabled(blink::features::kUnrestrictedUsb)) {
     is_usb_unrestricted =
-        requesting_frame_ &&
-        requesting_frame_->IsFeatureEnabled(
-            blink::mojom::PermissionsPolicyFeature::kUsbUnrestricted) &&
-        content::HasIsolatedContextCapability(requesting_frame_);
+        render_frame_host->IsFeatureEnabled(
+            network::mojom::PermissionsPolicyFeature::kUsbUnrestricted) &&
+        content::HasIsolatedContextCapability(render_frame_host);
   }
   // Isolated context with permission to access the policy-controlled feature
   // "usb-unrestricted" can bypass the USB blocklist.
