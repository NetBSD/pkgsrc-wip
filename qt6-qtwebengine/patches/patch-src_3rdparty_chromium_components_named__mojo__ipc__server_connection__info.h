$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/named_mojo_ipc_server/connection_info.h.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/components/named_mojo_ipc_server/connection_info.h
@@ -13,8 +13,14 @@
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
@@ -32,7 +38,7 @@ struct ConnectionInfo {
   absl::optional<base::win::ScopedHandle> impersonation_token{};
 #elif BUILDFLAG(IS_MAC)
   audit_token_t audit_token{};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ucred credentials{};
 #endif
 };
