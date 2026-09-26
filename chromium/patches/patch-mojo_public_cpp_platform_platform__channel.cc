$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- mojo/public/cpp/platform/platform_channel.cc.orig	2026-09-17 03:47:47.000000000 +0000
+++ mojo/public/cpp/platform/platform_channel.cc
@@ -144,6 +144,38 @@ void CreateChannel(PlatformHandle* local
   *remote_endpoint = PlatformHandle(std::move(receive));
 }
 #elif BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_NETBSD)
+// NetBSD's unp_send() silently drops both the data and the descriptors of a
+// sendmsg() whose SCM_RIGHTS control message does not fit in the receiver's
+// buffer, yet reports success: sosend() checks the space with the userland
+// control size (4 bytes per fd), then internalization grows it to 8 bytes per
+// fd. The stream then desyncs and the passed fds are lost. A sender can queue
+// at most its own SO_SNDBUF, so a receive buffer well above the peer's send
+// buffer keeps the internalized control message in range.
+void GrowReceiveBufferAbovePeerSendBuffer(int fd, int peer_fd) {
+  int sndbuf = 0;
+  socklen_t len = sizeof(sndbuf);
+  if (getsockopt(peer_fd, SOL_SOCKET, SO_SNDBUF, &sndbuf, &len) != 0 ||
+      sndbuf <= 0) {
+    PLOG(ERROR) << "getsockopt(SO_SNDBUF)";
+    return;
+  }
+  int rcvbuf = 0;
+  len = sizeof(rcvbuf);
+  if (getsockopt(fd, SOL_SOCKET, SO_RCVBUF, &rcvbuf, &len) != 0) {
+    PLOG(ERROR) << "getsockopt(SO_RCVBUF)";
+    return;
+  }
+  const int wanted = base::ClampMul(sndbuf, 2);
+  if (rcvbuf >= wanted) {
+    return;
+  }
+  if (setsockopt(fd, SOL_SOCKET, SO_RCVBUF, &wanted, sizeof(wanted)) != 0) {
+    PLOG(ERROR) << "setsockopt(SO_RCVBUF, " << wanted << ")";
+  }
+}
+#endif  // BUILDFLAG(IS_NETBSD)
+
 void CreateChannel(PlatformHandle* local_endpoint,
                    PlatformHandle* remote_endpoint) {
   int fds[2];
@@ -153,6 +185,11 @@ void CreateChannel(PlatformHandle* local
   PCHECK(fcntl(fds[0], F_SETFL, O_NONBLOCK) == 0);
   PCHECK(fcntl(fds[1], F_SETFL, O_NONBLOCK) == 0);
 
+#if BUILDFLAG(IS_NETBSD)
+  GrowReceiveBufferAbovePeerSendBuffer(fds[0], fds[1]);
+  GrowReceiveBufferAbovePeerSendBuffer(fds[1], fds[0]);
+#endif
+
   *local_endpoint = PlatformHandle(base::ScopedFD(fds[0]));
   *remote_endpoint = PlatformHandle(base::ScopedFD(fds[1]));
   DCHECK(local_endpoint->is_valid());
