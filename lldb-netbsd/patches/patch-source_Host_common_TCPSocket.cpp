$NetBSD$

--- source/Host/common/TCPSocket.cpp.orig	2018-02-02 18:39:02.000000000 +0000
+++ source/Host/common/TCPSocket.cpp
@@ -146,14 +146,17 @@ Status TCPSocket::Connect(llvm::StringRe
       host_str.c_str(), NULL, AF_UNSPEC, SOCK_STREAM, IPPROTO_TCP);
   for (auto address : addresses) {
     error = CreateSocket(address.GetFamily());
-    if (error.Fail())
+    if (error.Fail()) {
+      errno = 0;
       continue;
+    }
 
     address.SetPort(port);
 
     if (-1 == ::connect(GetNativeSocket(), &address.sockaddr(),
                         address.GetLength())) {
       CLOSE_SOCKET(GetNativeSocket());
+      errno = 0;
       continue;
     }
 
