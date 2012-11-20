$NetBSD: patch-mod__lisp2-1.2.c,v 1.1 2012/11/20 16:50:58 othyro Exp $

Needs to specify a protocol to apr_create_socket().

--- mod_lisp2-1.2.c.orig	2012-11-20 15:52:01.000000000 +0000
+++ mod_lisp2-1.2.c
@@ -325,7 +325,8 @@ open_lisp_socket (lisp_cfg_t * cfg)
 			    (cfg->server_port), 0, socket_pool));
 
   RELAY_ERROR
-    (apr_socket_create ((&socket), AF_INET, SOCK_STREAM, socket_pool));
+    (apr_socket_create ((&socket), AF_INET, SOCK_STREAM, APR_PROTO_TCP,
+			socket_pool));
 
   /* Should be apr_socket_connect */
   RELAY_ERROR (apr_connect (socket, addr));
