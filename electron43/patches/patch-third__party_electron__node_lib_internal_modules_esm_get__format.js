$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/modules/esm/get_format.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/lib/internal/modules/esm/get_format.js
@@ -32,6 +32,7 @@ const protocolHandlers = {
   'http:': getHttpProtocolModuleFormat,
   'https:': getHttpProtocolModuleFormat,
   'node:'() { return 'builtin'; },
+  'electron:'() { return 'electron'; },
 };
 
 /**
