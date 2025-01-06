$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_messaging.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_messaging.cc
@@ -907,7 +907,7 @@ Maybe<bool> MessagePort::PostMessage(Env
                                      const TransferList& transfer_v) {
   Isolate* isolate = env->isolate();
   Local<Object> obj = object(isolate);
-
+  TryCatchScope try_catch(env);
   std::shared_ptr<Message> msg = std::make_shared<Message>();
 
   // Per spec, we need to both check if transfer list has the source port, and
@@ -915,6 +915,10 @@ Maybe<bool> MessagePort::PostMessage(Env
 
   Maybe<bool> serialization_maybe =
       msg->Serialize(env, context, message_v, transfer_v, obj);
+  if (try_catch.HasCaught() &&
+      !try_catch.HasTerminated()) {
+    try_catch.ReThrow();
+  }
   if (data_ == nullptr) {
     return serialization_maybe;
   }
