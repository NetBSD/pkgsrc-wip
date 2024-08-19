$NetBSD$

NetBSD support.

--- folly/io/async/AsyncUDPSocket.cpp.orig	2024-08-19 19:46:57.582431959 +0000
+++ folly/io/async/AsyncUDPSocket.cpp
@@ -263,6 +263,7 @@ void AsyncUDPSocket::init(sa_family_t fa
             errno);
       }
     } else if (family == AF_INET) {
+#ifdef IP_RECVTOS
       if (netops::setsockopt(
               socket, IPPROTO_IP, IP_RECVTOS, &flag, sizeof(flag)) != 0) {
         throw AsyncSocketException(
@@ -270,6 +271,7 @@ void AsyncUDPSocket::init(sa_family_t fa
             "failed to set IP_RECVTOS on the socket",
             errno);
       }
+#endif
     }
   }
 
