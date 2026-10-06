$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/predictors/preconnect_manager.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/predictors/preconnect_manager.h
@@ -17,7 +17,9 @@
 #include "base/time/time.h"
 #include "chrome/browser/predictors/proxy_lookup_client_impl.h"
 #include "chrome/browser/predictors/resolve_host_client_impl.h"
+#if 0
 #include "chrome/browser/predictors/resource_prefetch_predictor.h"
+#endif
 #include "net/base/network_anonymization_key.h"
 #include "url/gurl.h"
 
@@ -33,7 +35,28 @@ class NetworkContext;
 
 namespace predictors {
 
-struct PreconnectRequest;
+// Stores all values needed to trigger a preconnect/preresolve job to a single
+// origin.
+struct PreconnectRequest {
+  // |network_anonymization_key| specifies the key that network requests for the
+  // preconnected URL are expected to use. If a request is issued with a
+  // different key, it may not use the preconnected socket. It has no effect
+  // when |num_sockets| == 0.
+  PreconnectRequest(
+      const url::Origin& origin,
+      int num_sockets,
+      const net::NetworkAnonymizationKey& network_anonymization_key);
+  PreconnectRequest(const PreconnectRequest&) = default;
+  PreconnectRequest(PreconnectRequest&&) = default;
+  PreconnectRequest& operator=(const PreconnectRequest&) = default;
+  PreconnectRequest& operator=(PreconnectRequest&&) = default;
+
+  url::Origin origin;
+  // A zero-value means that we need to preresolve a host only.
+  int num_sockets = 0;
+  bool allow_credentials = true;
+  net::NetworkAnonymizationKey network_anonymization_key;
+};
 
 struct PreconnectedRequestStats {
   PreconnectedRequestStats(const url::Origin& origin, bool was_preconnected);
