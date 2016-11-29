$NetBSD$

--- ipc/unix_domain_socket_util.cc.orig	2016-11-10 20:02:15.000000000 +0000
+++ ipc/unix_domain_socket_util.cc
@@ -156,7 +156,7 @@ bool CreateClientUnixDomainSocket(const 
 
 bool GetPeerEuid(int fd, uid_t* peer_euid) {
   DCHECK(peer_euid);
-#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   uid_t socket_euid;
   gid_t socket_gid;
   if (getpeereid(fd, &socket_euid, &socket_gid) < 0) {
