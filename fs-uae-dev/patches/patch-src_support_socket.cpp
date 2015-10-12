$NetBSD$

https://github.com/FrodeSolheim/fs-uae/issues/83

--- src/support/socket.cpp.orig	2015-10-02 20:06:18.000000000 +0000
+++ src/support/socket.cpp
@@ -164,8 +164,8 @@ uae_socket uae_tcp_listen_uri(
 
 uae_socket uae_socket_accept(uae_socket s)
 {
-	socklen_t sa_len = sizeof(SOCKADDR_INET);
-	char socketaddr[sizeof(SOCKADDR_INET)];
+	socklen_t sa_len = 64;
+	char socketaddr[64];
 	uae_socket result = accept(s, (struct sockaddr*) socketaddr, &sa_len);
 	return result;
 }
