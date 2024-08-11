$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/events/devices/x11/device_data_manager_x11.cc.orig	2024-07-24 02:45:10.460057500 +0000
+++ ui/events/devices/x11/device_data_manager_x11.cc
@@ -844,6 +844,7 @@ void DeviceDataManagerX11::SetDisabledKe
 }
 
 void DeviceDataManagerX11::DisableDevice(x11::Input::DeviceId deviceid) {
+  NOTIMPLEMENTED();
   blocked_devices_.set(static_cast<uint32_t>(deviceid), true);
   // TODO(rsadam@): Support blocking touchscreen devices.
   std::vector<KeyboardDevice> keyboards = GetKeyboardDevices();
