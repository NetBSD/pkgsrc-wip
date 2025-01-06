$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/modules/serial/serial_port_underlying_sink.h.orig	2024-10-18 12:34:36.139846000 +0000
+++ third_party/blink/renderer/modules/serial/serial_port_underlying_sink.h
@@ -20,6 +20,8 @@ class SerialPort;
 class WritableStreamDefaultController;
 
 class SerialPortUnderlyingSink final : public UnderlyingSinkBase {
+  USING_PRE_FINALIZER(SerialPortUnderlyingSink, Dispose);
+
  public:
   SerialPortUnderlyingSink(SerialPort*, mojo::ScopedDataPipeProducerHandle);
 
@@ -46,6 +48,7 @@ class SerialPortUnderlyingSink final : p
   void OnFlushOrDrain();
   void WriteData();
   void PipeClosed();
+  void Dispose();
 
   mojo::ScopedDataPipeProducerHandle data_pipe_;
   mojo::SimpleWatcher watcher_;
