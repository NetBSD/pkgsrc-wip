$NetBSD$

--- mojo/edk/embedder/platform_channel_utils_posix.cc.orig	2017-02-02 02:02:55.000000000 +0000
+++ mojo/edk/embedder/platform_channel_utils_posix.cc
@@ -36,7 +36,7 @@ bool IsRecoverableError() {
 
 bool GetPeerEuid(PlatformHandle handle, uid_t* peer_euid) {
   DCHECK(peer_euid);
-#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
+#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD) || defined(OS_NETBSD)
   uid_t socket_euid;
   gid_t socket_gid;
   if (getpeereid(handle.handle, &socket_euid, &socket_gid) < 0) {
