$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/network/url_loader.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ services/network/url_loader.cc
@@ -601,6 +601,9 @@ URLLoader::URLLoader(
           mojo::SimpleWatcher::ArmingPolicy::MANUAL,
           base::SequencedTaskRunner::GetCurrentDefault()),
       per_factory_orb_state_(context.GetMutableOrbState()),
+      report_raw_headers_(
+        request.trusted_params &&
+        request.trusted_params->report_raw_headers),
       devtools_request_id_(request.devtools_request_id),
       request_mode_(request.mode),
       request_credentials_mode_(request.credentials_mode),
@@ -874,7 +877,7 @@ void URLLoader::ConfigureRequest(
         &URLLoader::IsSharedDictionaryReadAllowed, base::Unretained(this)));
   }
 
-  if (devtools_request_id()) {
+  if (devtools_request_id() || report_raw_headers_) {
     url_request_->SetResponseHeadersCallback(base::BindRepeating(
         &URLLoader::SetRawResponseHeaders, base::Unretained(this)));
   }
@@ -1852,6 +1855,19 @@ void URLLoader::OnResponseStarted(net::U
   }
 
   response_ = BuildResponseHead();
+  if (raw_response_headers_ && report_raw_headers_) {
+    std::vector<network::mojom::HttpRawHeaderPairPtr> header_array;
+    size_t iterator = 0;
+    std::string name, value;
+    while (raw_response_headers_->EnumerateHeaderLines(&iterator, &name, &value)) {
+      network::mojom::HttpRawHeaderPairPtr pair =
+          network::mojom::HttpRawHeaderPair::New();
+      pair->key = name;
+      pair->value = value;
+      header_array.push_back(std::move(pair));
+    }
+    response_->raw_response_headers = std::move(header_array);
+  }
   DispatchOnRawResponse();
 
   // Parse and remove the Trust Tokens response headers, if any are expected,
