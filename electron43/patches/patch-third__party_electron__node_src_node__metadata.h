$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_metadata.h.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/node_metadata.h
@@ -6,7 +6,7 @@
 #include <string>
 #include "node_version.h"
 
-#if HAVE_OPENSSL
+#if 0
 #include <openssl/crypto.h>
 #if NODE_OPENSSL_HAS_QUIC
 #include <openssl/quic.h>
