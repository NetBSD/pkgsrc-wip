$NetBSD$

Use a more portable method for filling out a struct.

--- src/io/rich_presence.cpp.orig	2022-11-09 00:09:36.289495909 -0800
+++ src/io/rich_presence.cpp	2022-11-09 00:10:21.502304697 -0800
@@ -276,10 +276,8 @@
 {
 #ifndef DISABLE_RPC
 #if !defined(WIN32) && defined(AF_UNIX)
-    struct sockaddr_un addr =
-    {
-        .sun_family = AF_UNIX
-    };
+    struct sockaddr_un addr;
+    addr.sun_family = AF_UNIX;
     memset(addr.sun_path, 0, sizeof(addr.sun_path));
     snprintf(addr.sun_path, sizeof(addr.sun_path), "%s", path.c_str());
     if(connect(m_socket, (struct sockaddr *) &addr, sizeof(addr)) == -1)
