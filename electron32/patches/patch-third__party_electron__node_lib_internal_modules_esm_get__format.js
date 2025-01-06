$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/modules/esm/get_format.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/lib/internal/modules/esm/get_format.js
@@ -31,6 +31,7 @@ const protocolHandlers = {
   'http:': getHttpProtocolModuleFormat,
   'https:': getHttpProtocolModuleFormat,
   'node:'() { return 'builtin'; },
+  'electron:'() { return 'electron'; },
 };
 
 /**
