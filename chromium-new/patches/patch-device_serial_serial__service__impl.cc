$NetBSD$

--- device/serial/serial_service_impl.cc.orig	2016-06-24 01:02:22.000000000 +0000
+++ device/serial/serial_service_impl.cc
@@ -74,9 +74,14 @@ void SerialServiceImpl::Connect(
 }
 
 SerialDeviceEnumerator* SerialServiceImpl::GetDeviceEnumerator() {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+  return NULL;
+#else
   if (!device_enumerator_)
     device_enumerator_ = SerialDeviceEnumerator::Create();
   return device_enumerator_.get();
+#endif
 }
 
 bool SerialServiceImpl::IsValidPath(const mojo::String& path) {
