$NetBSD: patch-server_tests_test-websocket.c,v 1.2 2021/01/05 15:14:39 jperkin Exp $

Provide fallback definitions for MSG_NOSIGNAL (SunOS) and SOL_TCP (NetBSD)

--- server/tests/test-websocket.c.orig	2023-05-12 08:37:06.000000000 +0000
+++ server/tests/test-websocket.c
@@ -42,6 +42,10 @@
 #include "net-utils.h"
 #include "websocket.h"
 
+#if !defined(MSG_NOSIGNAL)
+#define MSG_NOSIGNAL	0
+#endif
+
 /*
 on data arrived on socket:
   try to read data, read again till error, handle error, on EAGAIN polling again
@@ -200,6 +204,9 @@ handle_client(int new_sock)
 {
     if (non_blocking) {
         red_socket_set_non_blocking(new_sock, true);
+#ifndef SOL_TCP
+#define SOL_TCP IPPROTO_TCP
+#endif
     }
 
     int enable = 1;
