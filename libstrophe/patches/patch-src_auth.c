$NetBSD$

Avoid conflicts with SHA1_* in libssl:

 https://github.com/strophe/libstrophe/pull/59/

--- src/auth.c.orig	2015-08-18 21:07:06.000000000 +0000
+++ src/auth.c
@@ -1187,10 +1187,10 @@ int _handle_component_auth(xmpp_conn_t *
     /* Feed the session id and passphrase to the algorithm.
      * We need to compute SHA1(session_id + passphrase)
      */
-    SHA1_Init(&mdctx);
-    SHA1_Update(&mdctx, (uint8_t*)conn->stream_id, strlen(conn->stream_id));
-    SHA1_Update(&mdctx, (uint8_t*)conn->pass, strlen(conn->pass));
-    SHA1_Final(&mdctx, md_value);
+    xmpp_SHA1_Init(&mdctx);
+    xmpp_SHA1_Update(&mdctx, (uint8_t*)conn->stream_id, strlen(conn->stream_id));
+    xmpp_SHA1_Update(&mdctx, (uint8_t*)conn->pass, strlen(conn->pass));
+    xmpp_SHA1_Final(&mdctx, md_value);
 
     digest = xmpp_alloc(conn->ctx, 2*sizeof(md_value)+1);
     if (digest) {
