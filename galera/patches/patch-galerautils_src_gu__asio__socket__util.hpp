$NetBSD$

NetBSD support.

--- galerautils/src/gu_asio_socket_util.hpp.orig	2022-11-02 06:09:14.000000000 +0000
+++ galerautils/src/gu_asio_socket_util.hpp
@@ -148,7 +148,7 @@ static struct tcp_info get_tcp_info(Sock
 {
     struct tcp_info tcpi;
     memset(&tcpi, 0, sizeof(tcpi));
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #if defined(__linux__)
     static int const level(SOL_TCP);
 #else /* FreeBSD */
@@ -162,7 +162,7 @@ static struct tcp_info get_tcp_info(Sock
         gu_throw_error(err) << "Failed to read TCP info from socket: "
                             << strerror(err);
     }
-#endif /* __linux__ || __FreeBSD__ */
+#endif /* __linux__ || __FreeBSD__ || __NetBSD__ */
     return tcpi;
 }
 
