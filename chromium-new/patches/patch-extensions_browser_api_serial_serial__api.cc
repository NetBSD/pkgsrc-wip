$NetBSD$

--- extensions/browser/api/serial/serial_api.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ extensions/browser/api/serial/serial_api.cc
@@ -85,12 +85,13 @@ bool SerialGetDevicesFunction::Prepare()
 
 void SerialGetDevicesFunction::Work() {
   DCHECK_CURRENTLY_ON(BrowserThread::FILE);
-
+#if !defined(OS_BSD)
   std::unique_ptr<device::SerialDeviceEnumerator> enumerator =
       device::SerialDeviceEnumerator::Create();
   mojo::Array<device::serial::DeviceInfoPtr> devices = enumerator->GetDevices();
   results_ = serial::GetDevices::Results::Create(
       devices.To<std::vector<serial::DeviceInfo>>());
+#endif
 }
 
 SerialConnectFunction::SerialConnectFunction() {
