$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- net/http/http_network_session.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ net/http/http_network_session.cc
@@ -20,7 +20,9 @@
 #include "build/build_config.h"
 #include "net/base/features.h"
 #include "net/dns/host_resolver.h"
+#if defined(USE_KERBEROS)
 #include "net/http/http_auth_handler_factory.h"
+#endif
 #include "net/http/http_response_body_drainer.h"
 #include "net/http/http_stream_factory.h"
 #include "net/http/http_stream_pool.h"
