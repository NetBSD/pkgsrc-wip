$NetBSD$

Add undeclared AI_* for NetBSD 

--- source/build/src/mmulti.cpp.orig	2020-03-10 00:00:02.000000000 +0000
+++ source/build/src/mmulti.cpp
@@ -68,6 +68,17 @@ LPFN_WSARECVMSG WSARecvMsgPtr;
 #endif
 #endif
 
+#ifndef AI_ALL 
+# define AI_ALL 0 
+#endif 
+#ifndef AI_V4MAPPED 
+# define AI_V4MAPPED 0 
+#endif 
+#ifndef AI_ADDRCONFIG 
+# define AI_ADDRCONFIG 0 
+#endif
+
+
 #include <unistd.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
