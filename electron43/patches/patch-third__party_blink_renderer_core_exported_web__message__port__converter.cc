$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/exported/web_message_port_converter.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/exported/web_message_port_converter.cc
@@ -6,6 +6,7 @@
 
 #include "third_party/blink/public/common/messaging/message_port_channel.h"
 #include "third_party/blink/renderer/bindings/core/v8/script_value.h"
+#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
 #include "third_party/blink/renderer/bindings/core/v8/v8_message_port.h"
 #include "third_party/blink/renderer/core/messaging/message_port.h"
 
@@ -21,4 +22,15 @@ WebMessagePortConverter::DisentangleAndE
   return port->Disentangle();
 }
 
+v8::Local<v8::Value>
+WebMessagePortConverter::EntangleAndInjectMessagePortChannel(
+    v8::Local<v8::Context> context,
+    MessagePortChannel port_channel) {
+  auto* execution_context = ToExecutionContext(context);
+  CHECK(execution_context);
+  auto* port = MakeGarbageCollected<MessagePort>(*execution_context);
+  port->Entangle(std::move(port_channel));
+  return port->ToV8(context->GetIsolate(), context->Global());
+}
+
 }  // namespace blink
