$NetBSD: patch-chrome_browser_renderer_host_render_sandbox_host_linux.cc,v 1.1 2011/03/28 10:14:50 rxg Exp $

--- chrome/browser/renderer_host/render_sandbox_host_linux.cc.orig	2010-10-15 08:03:54.000000000 +0000
+++ chrome/browser/renderer_host/render_sandbox_host_linux.cc
@@ -648,7 +648,12 @@ void RenderSandboxHostLinux::Init(const 
   // inherit some sockets. With PF_UNIX+SOCK_DGRAM, it can call sendmsg to send
   // a datagram to any (abstract) socket on the same system. With
   // SOCK_SEQPACKET, this is prevented.
+#if defined(OS_FREEBSD) || defined(OS_NETBSD)
+  if (socketpair(AF_UNIX, SOCK_SEQPACKET, 0, fds) != 0)
+    CHECK(socketpair(AF_UNIX, SOCK_DGRAM, 0, fds) == 0);
+#else
   CHECK(socketpair(AF_UNIX, SOCK_SEQPACKET, 0, fds) == 0);
+#endif
 
   renderer_socket_ = fds[0];
   const int browser_socket = fds[1];
