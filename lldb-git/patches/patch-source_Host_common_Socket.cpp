$NetBSD$

--- source/Host/common/Socket.cpp.orig	2017-02-02 23:56:41.000000000 +0000
+++ source/Host/common/Socket.cpp
@@ -443,11 +443,7 @@ NativeSocket Socket::AcceptSocket(Native
   if (!child_processes_inherit) {
     flags |= SOCK_CLOEXEC;
   }
-#if defined(__NetBSD__)
-  NativeSocket fd = ::paccept(sockfd, addr, addrlen, nullptr, flags);
-#else
   NativeSocket fd = ::accept4(sockfd, addr, addrlen, flags);
-#endif
 #else
   NativeSocket fd = ::accept(sockfd, addr, addrlen);
 #endif
