$NetBSD$

Fix parameter type

--- src/js/quickjs/heartbeat.c.orig	2026-07-26 09:58:12.000000000 +0000
+++ src/js/quickjs/heartbeat.c
@@ -33,7 +33,7 @@ int
  * Returning 1 terminates script execution immediately. */
 
 int
-js_heartbeat_callback(JSRuntime *rt, void *opaque)
+js_heartbeat_callback(JSContext *ctx, void *opaque)
 {
 	ELOG
 	struct ecmascript_interpreter *interpreter = (struct ecmascript_interpreter *)opaque;
