$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/network/url_loader.cc.orig	2024-10-18 12:34:32.113710400 +0000
+++ services/network/url_loader.cc
@@ -712,6 +712,7 @@ URLLoader::URLLoader(
         request.trusted_params->allow_cookies_from_browser;
     include_request_cookies_with_response_ =
         request.trusted_params->include_request_cookies_with_response;
+    report_raw_headers_ = request.trusted_params->report_raw_headers;
   }
 
   // Store any cookies passed from the browser process to later attach them to
@@ -750,7 +751,7 @@ URLLoader::URLLoader(
         &URLLoader::IsSharedDictionaryReadAllowed, base::Unretained(this)));
   }
 
-  if (devtools_request_id()) {
+  if (devtools_request_id() || report_raw_headers_) {
     url_request_->SetResponseHeadersCallback(base::BindRepeating(
         &URLLoader::SetRawResponseHeaders, base::Unretained(this)));
   }
@@ -1713,6 +1714,19 @@ void URLLoader::OnResponseStarted(net::U
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
