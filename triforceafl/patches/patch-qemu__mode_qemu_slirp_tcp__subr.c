$NetBSD$

Imported patch from qemu-2.3.0

--- qemu_mode/qemu/slirp/tcp_subr.c.orig	2017-05-31 22:53:05.000000000 +0000
+++ qemu_mode/qemu/slirp/tcp_subr.c
@@ -340,6 +340,8 @@ int tcp_fconnect(struct socket *so)
     socket_set_fast_reuse(s);
     opt = 1;
     qemu_setsockopt(s, SOL_SOCKET, SO_OOBINLINE, &opt, sizeof(opt));
+    opt = 1;
+    qemu_setsockopt(s, IPPROTO_TCP, TCP_NODELAY, &opt, sizeof(opt));
 
     addr.sin_family = AF_INET;
     if ((so->so_faddr.s_addr & slirp->vnetwork_mask.s_addr) ==
