$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/named_mojo_ipc_server/connection_info.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/named_mojo_ipc_server/connection_info.h
@@ -12,8 +12,14 @@
 #include "base/win/scoped_handle.h"
 #elif BUILDFLAG(IS_MAC)
 #include <bsm/libbsm.h>
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/socket.h>
+#if defined(__NetBSD__)
+#include <sys/un.h>
+#define ucred unpcbid
+#define SO_PEERCRED LOCAL_PEEREID
+#define pid unp_pid
+#endif
 #endif
 
 namespace named_mojo_ipc_server {
@@ -29,7 +35,7 @@ struct ConnectionInfo {
   base::ProcessId pid{};
 #if BUILDFLAG(IS_MAC)
   audit_token_t audit_token{};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ucred credentials{};
 #endif
 };
