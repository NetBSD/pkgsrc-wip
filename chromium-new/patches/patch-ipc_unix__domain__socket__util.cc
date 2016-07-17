$NetBSD$

--- ipc/unix_domain_socket_util.cc.orig	2016-06-24 01:02:23.000000000 +0000
+++ ipc/unix_domain_socket_util.cc
@@ -156,7 +156,7 @@ bool CreateClientUnixDomainSocket(const 
 
 bool GetPeerEuid(int fd, uid_t* peer_euid) {
   DCHECK(peer_euid);
-#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
+#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD) || defined(OS_NETBSD)
   uid_t socket_euid;
   gid_t socket_gid;
   if (getpeereid(fd, &socket_euid, &socket_gid) < 0) {
