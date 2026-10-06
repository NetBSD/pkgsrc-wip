$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/modules/websockets/websocket_channel_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/modules/websockets/websocket_channel_impl.cc
@@ -104,6 +104,17 @@ enum WebSocketOpCode {
   kOpCodeBinary = 0x2,
 };
 
+// When enabled, a page can be aggressively throttled even if it uses a
+// WebSocket. Aggressive throttling does not affect the execution of WebSocket
+// event handlers, so there is little reason to disable it on pages using a
+// WebSocket.
+//
+// TODO(crbug.com/1121725): Cleanup this feature in June 2021, when it becomes
+// enabled by default on Stable.
+BASE_FEATURE(kAllowAggressiveThrottlingWithWebSocket,
+             "AllowAggressiveThrottlingWithWebSocket",
+             base::FEATURE_ENABLED_BY_DEFAULT);
+
 }  // namespace
 
 WebSocketChannelImpl::MessageDataDeleter::MessageDataDeleter(
@@ -297,7 +308,10 @@ bool WebSocketChannelImpl::Connect(const
     // even if the `WebSocketChannel` is closed.
     feature_handle_for_scheduler_ = scheduler->RegisterFeature(
         SchedulingPolicy::Feature::kWebSocket,
-        SchedulingPolicy{SchedulingPolicy::DisableBackForwardCache()});
+        base::FeatureList::IsEnabled(kAllowAggressiveThrottlingWithWebSocket)
+            ? SchedulingPolicy{SchedulingPolicy::DisableBackForwardCache()}
+            : SchedulingPolicy{SchedulingPolicy::DisableAggressiveThrottling(),
+                               SchedulingPolicy::DisableBackForwardCache()});
     scheduler->RegisterStickyFeature(
         SchedulingPolicy::Feature::kWebSocketSticky,
         SchedulingPolicy{SchedulingPolicy::DisableBackForwardCache()});
