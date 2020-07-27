$NetBSD$

--- ui/events/devices/x11/device_data_manager_x11.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ ui/events/devices/x11/device_data_manager_x11.cc
@@ -875,6 +875,7 @@ void DeviceDataManagerX11::SetDisabledKe
 }
 
 void DeviceDataManagerX11::DisableDevice(int deviceid) {
+#if !defined(OS_BSD)
   blocked_devices_.set(deviceid, true);
   // TODO(rsadam@): Support blocking touchscreen devices.
   std::vector<InputDevice> keyboards = GetKeyboardDevices();
@@ -885,6 +886,9 @@ void DeviceDataManagerX11::DisableDevice
     keyboards.erase(it);
     DeviceDataManager::OnKeyboardDevicesUpdated(keyboards);
   }
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 void DeviceDataManagerX11::EnableDevice(int deviceid) {
