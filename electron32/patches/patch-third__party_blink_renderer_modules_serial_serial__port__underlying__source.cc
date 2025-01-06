$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/modules/serial/serial_port_underlying_source.cc.orig	2024-10-18 12:34:36.139846000 +0000
+++ third_party/blink/renderer/modules/serial/serial_port_underlying_source.cc
@@ -224,4 +224,10 @@ void SerialPortUnderlyingSource::Close()
   data_pipe_.reset();
 }
 
+void SerialPortUnderlyingSource::Dispose() {
+  // Ensure that `watcher_` is disarmed so that `OnHandleReady()` is not called
+  // after this object becomes garbage.
+  Close();
+}
+
 }  // namespace blink
