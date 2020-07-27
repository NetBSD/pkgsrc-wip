$NetBSD$

--- third_party/perfetto/include/perfetto/ext/base/unix_socket.h.orig	2020-06-25 09:34:47.000000000 +0000
+++ third_party/perfetto/include/perfetto/ext/base/unix_socket.h
@@ -321,7 +321,8 @@ class UnixSocket {
   int last_error_ = 0;
   uid_t peer_uid_ = kInvalidUid;
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
   pid_t peer_pid_ = kInvalidPid;
 #endif
   EventListener* const event_listener_;
