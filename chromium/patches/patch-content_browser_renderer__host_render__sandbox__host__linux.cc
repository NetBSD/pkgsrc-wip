$NetBSD: patch-content_browser_renderer__host_render__sandbox__host__linux.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- content/browser/renderer_host/render_sandbox_host_linux.cc.orig	2011-05-24 08:01:07.000000000 +0000
+++ content/browser/renderer_host/render_sandbox_host_linux.cc
@@ -335,7 +335,7 @@ class SandboxIPCProcess  {
       return;
     }
 
-    uint64_t inode;
+    uint64 inode;
     if (!pickle.ReadUInt64(&iter, &inode))
       return;
 
@@ -665,7 +665,12 @@ void RenderSandboxHostLinux::Init(const 
   // inherit some sockets. With PF_UNIX+SOCK_DGRAM, it can call sendmsg to send
   // a datagram to any (abstract) socket on the same system. With
   // SOCK_SEQPACKET, this is prevented.
+#if defined(OS_BSD)
+  if (socketpair(AF_UNIX, SOCK_SEQPACKET, 0, fds) != 0)
+    CHECK(socketpair(AF_UNIX, SOCK_DGRAM, 0, fds) == 0);
+#else
   CHECK(socketpair(AF_UNIX, SOCK_SEQPACKET, 0, fds) == 0);
+#endif
 
   renderer_socket_ = fds[0];
   const int browser_socket = fds[1];
