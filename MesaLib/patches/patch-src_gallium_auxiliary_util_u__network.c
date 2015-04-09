$NetBSD: patch-src_gallium_auxiliary_util_u__network.c,v 1.1 2015/04/09 08:38:33 tnn2 Exp $

BSD has sockets, silence warning about missing implementation.

--- src/gallium/auxiliary/util/u_network.c.orig	2014-09-12 21:30:32.000000000 +0000
+++ src/gallium/auxiliary/util/u_network.c
@@ -7,7 +7,7 @@
 #  include <winsock2.h>
 #  include <windows.h>
 #elif defined(PIPE_OS_LINUX) || defined(PIPE_OS_HAIKU) || \
-   defined(PIPE_OS_APPLE) || defined(PIPE_OS_CYGWIN) || defined(PIPE_OS_SOLARIS)
+   defined(PIPE_OS_APPLE) || defined(PIPE_OS_CYGWIN) || defined(PIPE_OS_SOLARIS) || defined(PIPE_OS_BSD)
 #  include <sys/socket.h>
 #  include <netinet/in.h>
 #  include <unistd.h>
@@ -55,8 +55,8 @@ u_socket_close(int s)
    if (s < 0)
       return;
 
-#if defined(PIPE_OS_LINUX) || defined(PIPE_OS_HAIKU) \
-    || defined(PIPE_OS_APPLE) || defined(PIPE_OS_SOLARIS)
+#if defined(PIPE_OS_LINUX) || defined(PIPE_OS_HAIKU) || \
+    || defined(PIPE_OS_APPLE) || defined(PIPE_OS_SOLARIS) || defined(PIPE_OS_BSD)
    shutdown(s, SHUT_RDWR);
    close(s);
 #elif defined(PIPE_SUBSYSTEM_WINDOWS_USER)
@@ -172,7 +172,7 @@ void
 u_socket_block(int s, boolean block)
 {
 #if defined(PIPE_OS_LINUX) || defined(PIPE_OS_HAIKU) \
-    || defined(PIPE_OS_APPLE) || defined(PIPE_OS_SOLARIS)
+    || defined(PIPE_OS_APPLE) || defined(PIPE_OS_SOLARIS) || defined(PIPE_OS_BSD)
    int old = fcntl(s, F_GETFL, 0);
    if (old == -1)
       return;
