$NetBSD: patch-src_gallium_auxiliary_util_u__network.c,v 1.1 2015/04/25 11:19:18 tnn Exp $

BSD has sockets, silence warning about missing implementation.

--- src/gallium/auxiliary/util/u_network.c.orig	2018-02-09 02:17:57.000000000 +0000
+++ src/gallium/auxiliary/util/u_network.c
@@ -10,7 +10,7 @@
 #  include <windows.h>
 #  include <ws2tcpip.h>
 #elif defined(PIPE_OS_LINUX) || defined(PIPE_OS_HAIKU) || \
-   defined(PIPE_OS_APPLE) || defined(PIPE_OS_CYGWIN) || defined(PIPE_OS_SOLARIS)
+   defined(PIPE_OS_APPLE) || defined(PIPE_OS_CYGWIN) || defined(PIPE_OS_SOLARIS) || defined(PIPE_OS_BSD)
 #  include <sys/socket.h>
 #  include <netinet/in.h>
 #  include <unistd.h>
@@ -59,7 +59,7 @@ u_socket_close(int s)
       return;
 
 #if defined(PIPE_OS_LINUX) || defined(PIPE_OS_HAIKU) \
-    || defined(PIPE_OS_APPLE) || defined(PIPE_OS_SOLARIS)
+    || defined(PIPE_OS_APPLE) || defined(PIPE_OS_SOLARIS) || defined(PIPE_OS_BSD)
    shutdown(s, SHUT_RDWR);
    close(s);
 #elif defined(PIPE_SUBSYSTEM_WINDOWS_USER)
@@ -182,7 +182,7 @@ void
 u_socket_block(int s, boolean block)
 {
 #if defined(PIPE_OS_LINUX) || defined(PIPE_OS_HAIKU) \
-    || defined(PIPE_OS_APPLE) || defined(PIPE_OS_SOLARIS)
+    || defined(PIPE_OS_APPLE) || defined(PIPE_OS_SOLARIS) || defined(PIPE_OS_BSD)
    int old = fcntl(s, F_GETFL, 0);
    if (old == -1)
       return;
