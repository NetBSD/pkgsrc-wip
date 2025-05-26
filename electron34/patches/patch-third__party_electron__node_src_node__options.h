$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_options.h.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/node_options.h
@@ -11,7 +11,7 @@
 #include "node_mutex.h"
 #include "util.h"
 
-#if HAVE_OPENSSL
+#if 0
 #include "openssl/opensslv.h"
 #endif
 
