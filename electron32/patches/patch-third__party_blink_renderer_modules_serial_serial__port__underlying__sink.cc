$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/modules/serial/serial_port_underlying_sink.cc.orig	2024-10-18 12:34:36.139846000 +0000
+++ third_party/blink/renderer/modules/serial/serial_port_underlying_sink.cc
@@ -268,4 +268,10 @@ void SerialPortUnderlyingSink::PipeClose
   abort_handle_.Clear();
 }
 
+void SerialPortUnderlyingSink::Dispose() {
+  // Ensure that `watcher_` is disarmed so that `OnHandleReady()` is not called
+  // after this object becomes garbage.
+  PipeClosed();
+}
+
 }  // namespace blink
