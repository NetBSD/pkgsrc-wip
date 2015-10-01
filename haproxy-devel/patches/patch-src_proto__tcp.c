$NetBSD$

--- src/proto_tcp.c.orig	2015-09-29 19:30:47.000000000 +0000
+++ src/proto_tcp.c
@@ -1456,7 +1456,7 @@ static enum act_return tcp_exec_action_s
 	 * network and has no effect on local net.
 	 */
 #ifdef IP_TTL
-	setsockopt(conn->t.sock.fd, SOL_IP, IP_TTL, &one, sizeof(one));
+	setsockopt(conn->t.sock.fd, IPPROTO_IP, IP_TTL, &one, sizeof(one));
 #endif
  out:
 	/* kill the stream if any */
