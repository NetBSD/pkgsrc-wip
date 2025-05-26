$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/handle_wrap.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/handle_wrap.cc
@@ -148,6 +148,9 @@ void HandleWrap::OnClose(uv_handle_t* ha
   wrap->OnClose();
   wrap->handle_wrap_queue_.Remove();
 
+  if (env->isolate()->IsExecutionTerminating())
+    return;
+
   if (!wrap->persistent().IsEmpty() &&
       wrap->object()->Has(env->context(), env->handle_onclose_symbol())
       .FromMaybe(false)) {
