$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/usb/usb_chooser_controller.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/usb/usb_chooser_controller.h
@@ -15,6 +15,7 @@
 #include "base/scoped_observation.h"
 #include "chrome/browser/usb/usb_chooser_context.h"
 #include "components/permissions/chooser_controller.h"
+#include "content/public/browser/global_routing_id.h"
 #include "services/device/public/mojom/usb_device.mojom.h"
 #include "third_party/blink/public/mojom/usb/web_usb_service.mojom.h"
 #include "url/origin.h"
@@ -64,8 +65,9 @@ class UsbChooserController : public perm
   blink::mojom::WebUsbService::GetPermissionCallback callback_;
   url::Origin origin_;
 
-  const raw_ptr<content::RenderFrameHost, AcrossTasksDanglingUntriaged>
-      requesting_frame_;
+  // Hold the GlobalRenderFrameHostId for requesting frame so we can always
+  // check whether the frame host is still valid before we access it.
+  const content::GlobalRenderFrameHostId render_frame_host_id_;
   base::WeakPtr<UsbChooserContext> chooser_context_;
   base::ScopedObservation<UsbChooserContext, UsbChooserContext::DeviceObserver>
       observation_{this};
