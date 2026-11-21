$NetBSD$

Fix parameter type

--- src/js/quickjs/heartbeat.h.orig	2026-07-26 09:58:12.000000000 +0000
+++ src/js/quickjs/heartbeat.h
@@ -23,7 +23,7 @@ void done_heartbeat(struct heartbeat *hb);
 struct heartbeat *add_heartbeat(struct ecmascript_interpreter *interpreter);
 void check_heartbeats(void *data);
 void done_heartbeat(struct heartbeat *hb);
-int js_heartbeat_callback(JSRuntime *rt, void *opaque);
+int js_heartbeat_callback(JSContext *ctx, void *opaque);
 
 #ifdef __cplusplus
 }
