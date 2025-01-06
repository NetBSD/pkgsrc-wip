$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/modules/serial/serial_port_underlying_source.h.orig	2024-10-18 12:34:36.139846000 +0000
+++ third_party/blink/renderer/modules/serial/serial_port_underlying_source.h
@@ -12,6 +12,7 @@
 #include "third_party/blink/renderer/bindings/core/v8/script_value.h"
 #include "third_party/blink/renderer/core/execution_context/execution_context_lifecycle_observer.h"
 #include "third_party/blink/renderer/core/streams/underlying_byte_source_base.h"
+#include "third_party/blink/renderer/platform/heap/prefinalizer.h"
 
 namespace blink {
 
@@ -20,6 +21,8 @@ class SerialPort;
 
 class SerialPortUnderlyingSource : public UnderlyingByteSourceBase,
                                    ExecutionContextLifecycleObserver {
+  USING_PRE_FINALIZER(SerialPortUnderlyingSource, Dispose);
+
  public:
   SerialPortUnderlyingSource(ScriptState*,
                              SerialPort*,
@@ -47,6 +50,7 @@ class SerialPortUnderlyingSource : publi
   void OnFlush(ScriptPromiseResolver<IDLUndefined>*);
   void PipeClosed();
   void Close();
+  void Dispose();
 
   // TODO(crbug.com/1457493) : Remove when debugging is done.
   MojoResult invalid_data_pipe_read_result_ = MOJO_RESULT_OK;
